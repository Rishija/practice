/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false

Example 2:

Input: [[7,10],[2,4]]
Output: true
*/

// Method 1
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

bool canAttendMeetings(vector<vector<int>>& A) {
    if(A.size() < 2)
        return true;

    // Sort by increasing starting time
    sort(A.begin(), A.end(), [] (const vi &a, const vi &b) {
        return a[0] < b[0];
    });

    for(int i = 0; i < A.size() - 1; ++i)
        if(A[i][1] > A[i + 1][0])
            return false;
    return true;
}

// Method 2
typedef pair<int, bool> Pair;

bool canAttendMeetings(vector<vector<int>>& A) {
    vector<Pair> v;

    // Single collection of entry and exit
    for(const vector<int> &interval : A) {
        v.push_back({interval[0], true});
        v.push_back({interval[1], false});
    }

    // Sort by increasing starting time, if same time, put exit first
    sort(v.begin(), v.end(), [] (const Pair &a, const Pair &b) {
        if(a.first == b.first)
            return a.second == false;
        return a.first < b.first;
    });

    // Initially there is no meeting going on
    bool flag = false;
    for(const Pair &p : v) {
        // There is a new meeting entry point
        if(p.second) {
            // There is already a meeting going on
            if(flag)
                return false;
        }
        flag = p.second;
    }
    return true;
}
