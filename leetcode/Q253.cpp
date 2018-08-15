/*
 Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
 
 Example 1:
 
 Input: [[0, 30],[5, 10],[15, 20]]
 Output: 2
 Example 2:
 
 Input: [[7,10],[2,4]]
 Output: 1
 */

int minMeetingRooms(vector<Interval>& A) {
    int n = A.size(); if(n < 2) return n;
    sort(A.begin(), A.end(), [] (const Interval &a, const Interval &b) {
        if(a.start == b.start)   return a.end < b.end;
        return a.start < b.start;
    });
    
    int maxx = 0, rooms = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(auto meeting : A) {
        q.push(meeting.end);
        while(q.top() <= meeting.start) {
            q.pop();
            --rooms;
        }
        ++rooms;
        maxx = max(maxx, rooms);
    }
    return maxx;
}
