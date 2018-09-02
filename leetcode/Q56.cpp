/*

 Given a collection of intervals, merge all overlapping intervals.

 Example 1:

 Input: [[1,3],[2,6],[8,10],[15,18]]
 Output: [[1,6],[8,10],[15,18]]
 Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 Example 2:

 Input: [[1,4],[4,5]]
 Output: [[1,5]]
 Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n < 2)   return intervals;

        sort(intervals.begin(), intervals.end(), [] (const Interval &a, const Interval &b) {
            if(a.start == b.start)   return a.end < b.end;
            return a.start < b.start;
        });

        vector<Interval> ans;
        int i = 0;
        while(i < n) {
            int end = intervals[i].end, j = i;
            while(j < n && intervals[j].start <= end) {
                end = max(end, intervals[j].end);
                ++j;
            }
            ans.push_back({intervals[i].start, end});
            i = j;
        }
        return ans;
    }
};
