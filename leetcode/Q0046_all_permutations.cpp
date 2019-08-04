/*
 Given a collection of distinct numbers, return all possible permutations.
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
void enter(vector<bool> visited, vvi &ans, vector<int> temp, int n, const vector<int> &nums) {
    
    bool found = false;
    
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            
            found = true;
            
            temp.push_back(nums[i]);
            visited[i] = true;
            
            enter(visited, ans, temp, n, nums);
            
            temp.pop_back();
            visited[i] = false;
        }
    }
    
    if(!found)
        ans.push_back(temp);
}

vector<vector<int>> permute1(vector<int>& nums) {
    
    vvi ans;
    vector<bool> empty(nums.size());
    enter(empty, ans, {}, nums.size(), nums);
    return ans;
}


/* Method 2 */

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
    
    for(auto i = nums.begin(); i != nums.end(); ++i) {
        
        newNum.clear();
        newNum.insert(newNum.end(), nums.begin(), i);
        if(i != nums.end() - 1)
            newNum.insert(newNum.end(), i + 1, nums.end());
        temp.push_back(*i);
        
        helper(ans, temp, newNum);
        temp.pop_back();
    }
}

vector<vector<int>> permute2(vector<int>& nums) {
    
    vvi ans;
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
    
    v = {1};
    print(v);
    
    return 0;
}
