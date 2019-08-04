/*
In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty.

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Note:

1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.
*/

int maxDistToClosest(vector<int>& A) {
    int n = A.size(), i = 0, j = n - 1;
    // Leading zeros
    while(i < n && A[i] == 0) ++i;
    // Ending zeros
    while(j >= 0 && A[j] == 0) --j;

    int corner = max(i, n - j - 1),
    // All cases
    middle = getLongestConsecutiveZero(A);
    float maxFromCenter = middle / (float) 2;
    return (corner >= maxFromCenter) ? corner : ceil(maxFromCenter);
}

int getLongestConsecutiveZero(vector<int> &A) {
    int n = A.size(), maxx = 0, curStart = 0;
    for(int i = 0; i < n; ++i) {
        if(A[i] == 0) {
            if(i - curStart + 1 > maxx)
                maxx = i - curStart + 1;
        } else
            curStart = i + 1;
    }
    return maxx;
}
