/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

vector<int> plusOne(vector<int>& A) {
    int n = A.size();
    if(n == 0)
        return A;

    bool carry = 1;
    for(int i = n - 1; i >= 0; --i) {
        if(carry) {
            A[i] = (A[i] + 1) % 10;
            // No change in incoming digits
            if(A[i] != 0)
                return A;
        }
    }
    if(carry)
        A.insert(A.begin(), 1);
    return A;
}
