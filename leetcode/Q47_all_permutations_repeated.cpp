/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 */

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

/*
 Time : O(n^n)
 Space : O(n)
 */
void helper(vvi &ans, vi temp, vi nums) {
    
    if(nums.size() == 0) {
        ans.push_back(temp);
        return;
    }
    
    vi newNum;
    int current;
    
    for(auto i = nums.begin(); i != nums.end(); ++i) {
        
        newNum.clear();
        newNum.insert(newNum.end(), nums.begin(), i);
        
        // i + 1 may give segmentation fault when i points to last element in the vector `num`
        if(i != nums.end() - 1)
            newNum.insert(newNum.end(), i + 1, nums.end());
        temp.push_back(*i);
        
        helper(ans, temp, newNum);
        
        // skip adding same element at current index
        current = *i;
        while(*i == current && i != nums.end())
            ++i;
        -- i;
        temp.pop_back();
    }
}

vector<vector<int>> permute2(vector<int>& nums) {
    
    vvi ans;
    sort(nums.begin(), nums.end());
    helper(ans, {}, nums);
    return ans;
}

ostream& operator << (ostream &os, vi v) {
    
    cout << "[ ";
    for(int x : v)
        os << x << ", ";
    cout << " ]";
    return os;
    
}

void print(vi v) {
    
    vvi ans = permute2(v);
    for(vi x : ans)
        cout << x << endl;
    cout << endl;
}


int main() {
    
    vector<int> v = {1,2,3};
    print(v);
    
    v = {1, 2, 1};
    print(v);
    
    v = {1, 2, 1, 1, 2};
    print(v);
    
    return 0;
}
