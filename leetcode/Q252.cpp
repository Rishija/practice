/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: [[7,10],[2,4]]
Output: true
*/

bool canAttendMeetings(vector<Interval>& intervals) {
    if(intervals.size() < 2)    return true;
    sort(intervals.begin(), intervals.end(), [] (const Interval &a, const Interval &b) {
        return a.start < b.start;
    });
    for(int i = intervals.size() - 1; i > 0; --i) {
        if(intervals[i].start < intervals[i-1].end)
            return false;
    }
    return true;
}
