/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

string decodeString(string A) {
    // Stores number of times a substring should be repeated
    stack<int> cnt;
    // Stores substring
    stack<string> s;
    
    for(int i = 0; i < A.size(); ++i) {
        char x = A[i];
        // Number
        if(isdigit(x)) {
            int j = i;
            while(isdigit(A[j]))
                ++j;
            cnt.push(stoi(A.substr(i, j - i)));
            i = j - 1;
            continue;
        }
        // Substring
        if(x == '[' || (isalpha(x))) {
            s.push(string(1, x));
            continue;
        }
        // End of a substring
        string thisString, toBePushed;
        while(s.top() != "[") {
            thisString += s.top();
            s.pop();
        }
        s.pop();
        int times = cnt.top();
        cnt.pop();
        // Repeat this substring required number of times
        while(times--)
            toBePushed += thisString;
        s.push(toBePushed);
    }
    string ans;
    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
