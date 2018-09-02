/*
 Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
 
 Example 1:
 
 Input: num1 = "2", num2 = "3"
 Output: "6"
 Example 2:
 
 Input: num1 = "123", num2 = "456"
 Output: "56088"
 Note:
 
 The length of both num1 and num2 is < 110.
 Both num1 and num2 contain only digits 0-9.
 Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

string multiply(string A, string B) {
    int n = A.size(), m = B.size();
    vector<int> digits (n + m);
    
    for(int i = n-1; i >= 0; --i) {
        for(int j = m-1; j >= 0; --j) {
            int num = (A[i] - 48) * (B[j] - 48),
            totalSum = num + digits[i + j + 1];    // previous digit plus new sum
            digits[i + j + 1] = totalSum % 10;     // Add sum
            digits[i + j] += totalSum / 10;        // Add carry
        }
    }
    int index = 0;
    while(index < (m + n) && digits[index] == 0)   ++index;
    if(index == m + n)    return "0";
    string anss = "";
    for(int i = index; i < (m + n); ++i)
        anss += to_string(digits[i]);
    return anss;
}
