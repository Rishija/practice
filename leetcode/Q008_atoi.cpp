/*
 Implement atoi which converts a string to an integer.
 
 The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 
 The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 
 If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 
 If no valid conversion could be performed, a zero value is returned.
 
 Note:
 
 Only the space character ' ' is considered as whitespace character.
 Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 */

int method1(string &A) {
    int n = A.size(), i = 0;
    while(i < n && A[i] == ' ') ++i;
    if(i == n) return 0;
    
    int sign = 1;
    if(A[i] == '-') { sign = -1; ++i; }
    else if(A[i] == '+') ++i;
    
    if(i == n || A[i] < 48 || A[i] > 57)    return 0;
    
    long long int ans = 0;
    while(i < n && A[i] >= 48 && A[i] <= 57) {
        ans = ans * 10 + A[i] - 48;
        if(sign * ans <= INT_MIN) return INT_MIN;
        if(sign * ans >= INT_MAX) return INT_MAX;
        ++i;
    }
    return sign * ans;
}

int method2(string &A) {
    int n = A.size(), i = 0;
    while(i < n && A[i] == ' ') ++i;
    if(i == n) return 0;
    
    int sign = 1;
    if(A[i] == '-') { sign = -1; ++i; }
    else if(A[i] == '+') ++i;
    
    if(i == n || A[i] < 48 || A[i] > 57)    return 0;
    
    long long int ans = 0;
    while(i < n && A[i] >= 48 && A[i] <= 57) {
        ans = ans * 10 + A[i] - 48;
        if(abs(ans) >= abs((long)INT_MIN)) break;
        ++i;
    }
    ans *= sign;
    if(ans <= INT_MIN) return INT_MIN;
    if(ans >= INT_MAX) return INT_MAX;
    return ans;
}

int method3(string &A) {
    int n = A.size(), i;
    for(i = 0; i < n && A[i] == ' '; ++i);
    if(i == n)  return 0;
    bool sign = false;
    if(A[i] == '-' || A[i] == '+') { if(A[i] == '-') sign = true; ++i; }
    if(i == n || A[i] < 48 || A[i] > 57)  return 0;
    
    long long int ans = 0;
    if(sign) {
        for(;i < n && A[i] >= 48 && A[i] <= 57; ++i) {
            ans = ans * 10 + A[i] - 48;
            if(ans >= INT_MAX + 1ll)  return INT_MIN;
        }
    }
    else {
        for(;i < n && A[i] >= 48 && A[i] <= 57; ++i) {
            ans = ans * 10 + A[i] - 48;
            if(ans >= INT_MAX)  return INT_MAX;
        }
    }
    return sign ? -1 * ans : ans;
}
int myAtoi(string A) {
    // return method1(A);
    // return method2(A);
    return method3(A);
}
