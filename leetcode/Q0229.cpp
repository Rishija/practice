/*
 Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 Note: The algorithm should run in linear time and in O(1) space.

 Example 1:

 Input: [3,2,3]
 Output: [3]
 Example 2:

 Input: [1,1,1,3,3,2,2,2]
 Output: [1,2]
 */


 class Solution {
public:
    vector<int> majorityElement(vector<int>& A) {
        int n = A.size(); if(n < 2) return A;
        int num1 = INT_MIN, num2 = INT_MIN, cnt1 = 0, cnt2 = 0;
        for(int &x : A) {
            if(x == num1) {
                ++cnt1;
                continue;
            }
            if(x == num2) {
                ++cnt2;
                continue;
            }
            if(cnt1 <= 0) {
                num1 = x;
                cnt1 = 1;
                continue;
            }
            if(cnt2 <= 0 && x != num1) {
                num2 = x;
                cnt2 = 1;
                continue;
            }
            --cnt1;
            --cnt2;
        }

        cnt1 = 0; cnt2 = 0;
        for(int &x : A) {
            if(x == num1) ++cnt1;
            else if(x == num2) ++cnt2;
        }

        vector<int> ans;
        if(cnt1 > n/3) ans.push_back(num1);
        if(cnt2 > n/3) ans.push_back(num2);
        return ans;
        // Generic : for elements repeating n/k times
        //         int k = 3;
        //         int n = A.size(); if(n < 2) return A;
        //         unordered_map<int, int> map;
        //         for(const auto &x : A) {
        //             if(map.size() < k-1 || map.find(x) != map.end())
        //                 ++map[x];
        //             else {
        //                 vector<int> temp;
        //                 for(auto &p : map)
        //                     if(--p.second == 0) temp.push_back(p.first);
        //                 for(auto key : temp)
        //                     map.erase(key);
        //             }
        //         }

        //         vector<int> ans;
        //         for(auto &p : map) {
        //             int cnt = 0;
        //             for(int x : A) if(x == p.first) ++cnt;
        //             if(cnt > n/3) ans.push_back(p.first);
        //         }
        //         return ans;
    }
};
