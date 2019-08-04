/*
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
*/

string nextClosestTime(string A) {
    set<char> s;
    s.insert(A[0]);
    s.insert(A[1]);
    s.insert(A[3]);
    s.insert(A[4]);

    // Find digit, larger than current digit
    string smallest(1, justLarger(s, '.'));
    char x = justLarger(s, A[4]);
    // Valid digit
    if(x != 'a')
        return A.substr(0, 4) + x;

    x = justLarger(s, A[3]);
    // Valid digit at minutes (tens place) must be < 6
    if(x < '6')
        return A.substr(0, 3) + x + smallest;

    x = justLarger(s, A[1]);
    if(A[0] == '2') {
        // Max hrs is 23
        if(x < '4')
            return A.substr(0, 1) + x + ":" + smallest + smallest;
        // Smallest time on next day
        else
            return smallest + smallest + ":" + smallest + smallest;
    }
    // Update invalid char
    if(x == 'a')
        x = smallest[0];
    return string(1,A[0]) + x + ":" + smallest + smallest;
}

char justLarger(const set<char> &s, char x) {
    for(char c : s)
        if(c > x)
            return c;
    return 'a';
}
