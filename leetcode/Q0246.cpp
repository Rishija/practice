/*
 A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 
 Write a function to determine if a number is strobogrammatic. The number is represented as a string.
 
 Example 1:
 
 Input:  "69"
 Output: true
 Example 2:
 
 Input:  "88"
 Output: true
 Example 3:
 
 Input:  "962"
 Output: false
 */

bool isStrobogrammatic(string num) {
    int n = num.size();
    for(int i = 0; i < n; ++i) {
        if(num[i] == '1' && num[n - i - 1] == '1') continue;
        if(num[i] == '0' && num[n - i - 1] == '0')  continue;
        if(num[i] == '8' && num[n - i - 1] == '8') continue;
        if(num[i] == '6' && num[n - i - 1] == '9') continue;
        if(num[i] == '9' && num[n - i - 1] == '6') continue;
        return false;
    }
    return true;
}
