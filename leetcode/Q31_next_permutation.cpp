/*
 Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 
 If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 Time : O(n)
 Space : O(1)
 */
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void nextPermutation(vector<int>& nums) {
    
    
    int n = nums.size();
    for(auto i = nums.end() - 1; i != nums.begin(); --i) {
        
        if(*(i-1) < *i) {
            
            // at pivot point, left element is  greater than last
            if(*(i-1) >= *(nums.end() - 1)) {
                
                // Find element just greater than left
                auto j = nums.end() - 1;
                while(true) {
                    if(*j > *(i-1))
                        break;
                    --j;
                }
                swap(*(i-1), *j);
            }
            
            // left element is the smallest
            else
                swap(*(i-1), *(nums.end() - 1));
            
            sort(i, nums.end());
            return;
        }
    }
    reverse(nums.begin(), nums.end());
}

void print(vector<int> &v) {
    
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << ", ";
    cout << "\t->\t";
    
    nextPermutation(v);
    
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << ", ";
    cout << endl;
}

int main() {
    
    vector<int> v = {1,2,3,4,5};
    print(v);
    
    v = {1,2,5,4,3};
    print(v);
    
    v = {1,2,4,5,6,3};   // 1 2 4 6 3 5
    print(v);
    
    v = {2,3,1};        // 3 1 2
    print(v);
    
    v = {5,4,3,2,1};
    print(v);
    
    v = {1,1,5};
    print(v);
    
    v = {1,5,1};    // 5 1 1
    print(v);
    
    v = {2,1,2,2,2,2,2,1};  // 2 2 1 1 2 2 2 2]
    print(v);
    
    return 0;
}
