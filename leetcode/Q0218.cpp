/*
 A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

 Buildings  Skyline Contour
 The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

 For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

 The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

 For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

 Notes:

 The number of buildings in any input list is guaranteed to be in the range [0, 10000].
 The input list is already sorted in ascending order by the left x position Li.
 The output list must be sorted by the x position.
 There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
*/

struct info {
    int x, end, height; bool type;
    info(int x, int end, int height, bool type) : x(x), end(end), height(height), type(type) {}
};

class cmp {
public:
    bool operator() (const info &a, const info &b) {
        if(a.height == b.height)    return a.end > b.end;
        return a.height < b.height;
    };
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<info> vec;
        for(auto v : buildings) {
            vec.push_back({v[0], v[1], v[2], 0});   // Starting
            vec.push_back({v[1], v[1], v[2], 1});   // Ending
        }

        sort(vec.begin(), vec.end(), [] (const info &a, const info &b) {
            if(a.x == b.x) {
                if(a.height == b.height)    return a.type == 0; // If arrival and height same, put `start` first
                return a.height > b.height;                     // Put largest first
            }
            return a.x < b.x;               // Time of arrival
        });

        vector<pair<int, int>> ans;
        priority_queue<info, vector<info>, cmp> pq;

        for(auto &v : vec) {
            // Remove expired buildings
            while(!pq.empty() && pq.top().end < v.x)    pq.pop();
            if(v.type == 0) {
                if(pq.empty() || v.height > pq.top().height)    ans.push_back({v.x, v.height}); // New large building
                pq.push(v);
            }
            else {
                if(pq.top().height == v.height) { // If removing this building affects heap max
                    pq.pop();
                    // Remove remaining expired buildings
                    while(!pq.empty() && pq.top().end < v.x)    pq.pop();
                    int thisHeight = pq.empty() ? 0 : pq.top().height;
                    if(ans[ans.size()-1].first == v.x) {
                        ans.pop_back(); // Remove last item if new item lies on same (x = fix) line
                        ans.push_back({v.x, thisHeight});
                    }
                    // Add only if y-coordinate has changed
                    else if(ans[ans.size()-1].second != thisHeight) ans.push_back({v.x, thisHeight});
                }
            }
        }

        return ans;
    }
};
