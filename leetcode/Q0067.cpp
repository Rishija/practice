/*
 Given two binary strings, return their sum (also a binary string).

 The input strings are both non-empty and contains only characters 1 or 0.

 Example 1:

 Input: a = "11", b = "1"
 Output: "100"
 Example 2:

 Input: a = "1010", b = "1011"
 Output: "10101"
 */

class Solution {
public:
    string addBinary(string a, string b) {
        string &A = a.size() >= b.size() ? a : b,
        &B = a.size() < b.size() ? a : b;
        A = "0" + A;
        int n = A.size(), m = B.size();
        if(m == 0)  return A;

        bool carry = false;
        int i = n-1, j = m-1;
        while(j >= 0) {
            bool x = A[i] - 48, y = B[j] - 48;
            A[i] = (x ^ y ^ carry) + 48;
            carry = (x && y) || (y && carry) || (carry && x);
            --i; --j;
        }
        while(i >= 0) {
            bool x = A[i] - 48;
            A[i] = (x ^ carry) + 48;
            carry = x && carry;
            --i;
        }

        i = 0;
        while(i < n && A[i] == '0') ++i;
        if(i == n)  return "0";
        return A.substr(i);
    }
};
