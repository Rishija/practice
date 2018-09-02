/*
 Count the number of prime numbers less than a non-negative number, n.

 Example:

 Input: 10
 Output: 4
 Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

 */

class Solution {
public:
    int countPrimes(int n) {
        if(n < 3)   return 0;

        int cnt = n - 2; // Exclude 1 and number itself
        vector<int> A(n);

        for(int i = 2; i < sqrt(n); ++i) {
            // If number is not composite
            if(A[i] == false) {
                // Start mul with `i` because any number of the form (i * mul) where num < i, must have already been visited
                for(int mul = i; mul * i < n; ++mul) {
                    // Do not decrement count if number is already marked composite
                    if(A[mul * i] == false)
                        --cnt;
                    A[mul * i] = true;

                }
            }
        }
        return cnt;
    }
};
// 999983
// 1500000
