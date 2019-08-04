/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 
 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 
 Write the code that will take a string and make this conversion given a number of rows:
 
 string convert(string s, int numRows);
 Example 1:
 
 Input: s = "PAYPALISHIRING", numRows = 3
 Output: "PAHNAPLSIIGYIR"
 Example 2:
 
 Input: s = "PAYPALISHIRING", numRows = 4
 Output: "PINALSIGYAHRPI"
 */

string convert(string s, int numRows) {
    size_t n = s.size();
    if(numRows >= n || numRows == 1)
        return s;
    
    string ans;
    ans.resize(n);
    int cnt = 2, gap = (numRows-1)*2, index = 0;
    
    for(int i = 0; i < n; i += gap) {
        ans[index] = s[i];
        ++index;
    }
    
    for(int i = 1; i < numRows - 1; ++i) {
        bool flag = true;
        int j = i;
        while(j < n) {
            ans[index] = s[j];
            ++index;
            j += flag ? gap - cnt : cnt;
            flag ^= 1;
        }
        cnt +=2;
    }
    
    for(int i = numRows - 1; i < n; i += gap) {
        ans[index] = s[i];
        ++index;
    }
    
    return ans;
}
