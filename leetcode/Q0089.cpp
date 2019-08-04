/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

Example 1:

Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1
*/

vector<int> grayCode(int n) {
    if(n == 0)  return {0};
    vector<int> prev = grayCode(n-1);
    int size = prev.size() * 2;
    prev.resize(size);
    for(int i = size/2 - 1; i >= 0; --i) {
        prev[i] *= 2;
        prev[size - i - 1] = prev[i] + 1;
    }
    return prev;
//    vector<int> prev = grayCode(n-1), ans;
//    for(int i = 0; i < prev.size(); ++i)
//        ans.push_back(2 * prev[i]);
//    for(int i = prev.size() - 1; i >= 0; --i)
//        ans.push_back(2 * prev[i] + 1);
//    return ans;
}
