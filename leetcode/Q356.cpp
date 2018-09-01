/*
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Input: [[1,1],[-1,1]]
Output: true
 
Example 2:
Input: [[1,1],[-1,-1]]
Output: false
 
Follow up:
Could you do better than O(n2) ?
*/

class Solution {
public:
    using pii = pair<int,int>;
    bool helper1(vector<pii> &A) {
        int n = A.size();
        if(n < 2)
            return true;
        int left = A[0].first, right = A[0].first;
        for(int i = 1; i < n; ++i) {
            left = min(left, A[i].first);
            right = max(right, A[i].first);
        }
        
        int center1 = floor(((double)right + left) / 2), center2 = center1;
        if((left + right) % 2)
            ++center2;
        sort(A.begin(), A.end(), [center1] (const pii &a, const pii &b) {
            if(a.first == b.first) {
                if(a.first <= center1) return a.second > b.second;
                return a.second <= b.second;
            }
            return a.first < b.first;
        });
        
        left = 0; right = n-1;
        while(left <= right) {
            if(A[left].first == A[right].first)
                return A[left].first == center1 && A[right].first == center2;
            if((center1 - A[left].first != A[right].first - center2) || (A[left].second != A[right].second))
                return false;
            while(left + 1 <= right && A[left] == A[left + 1])
                ++left;
            while(right - 1 >= left && A[right] == A[right - 1])
                --right;
            ++left;
            --right;
        }
        return true;
    }
    
    bool helper2(vector<pii> &A) {
        if(A.size() < 2)    return true;
        unordered_set<long long int> map;
        
        int minn = A[0].first, maxx = A[0].first;
        for(const auto &p : A) {
            map.insert(((long long int)p.first << 32) + p.second);
            minn = min(minn, p.first);
            maxx = max(maxx, p.first);
        }
        
        long long int deviation = (minn + maxx) / 2;
        for(const auto &p : A) {
            if(map.find(((deviation - p.first) << 32) + p.second) == map.end())
                return false;
        }
        return true;
    }
    
    bool isReflected(vector<pair<int, int>>& points) {
        return helper1(points);
        // return helper2(points);
    }
};
// [[-16,1],[16,1],[16,1]]      t
// [[0,0],[1,0],[3,0]]          f
// [[1,1],[-1,1]]               t
// [[1,1],[-4,1]]               t
// [[-10,10],[-11,11],[-9,11]]  t
// [[0,0],[0,-1]]               t
// [[0,0],[1,0],[3,0]]          f
