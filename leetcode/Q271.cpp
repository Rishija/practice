/*
 
 Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.
 
 Machine 1 (sender) has the function:
 
 string encode(vector<string> strs) {
     // ... your code
     return encoded_string;
 }
 
 Machine 2 (receiver) has the function:
 vector<string> decode(string s) {
     //... your code
     return strs;
 }
 
 So Machine 1 does:
 string encoded_string = encode(strs);
 
 and Machine 2 does:
 vector<string> strs2 = decode(encoded_string);
 strs2 in Machine 2 should be the same as strs in Machine 1.
 
 Implement the encode and decode methods.
 
 Note:
 The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
 Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
 Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
 */

// Encodes a list of strings to a single string.
string encode(vector<string>& strs) {
    
    int n = strs.size();
    string ans = to_string(n) + "#";
    for(string s : strs)    ans += to_string(s.size()) + "#";
    for(string s : strs)    ans += s;
    return ans;
}

// Decodes a single string to a list of strings.
vector<string> decode(string s) {
    
    int i = 0, j = 0;
    while(s[i] != '#')  ++i;
    int n = stoi(s.substr(0, i-j));
    ++i;
    
    vector<int> lengths;
    for(int cnt = 0; cnt < n; ++cnt) {
        j = i;
        while(s[i] != '#') ++i;
        lengths.push_back(stoi(s.substr(j,i-j)));
        ++i;
    }
    
    vector<string> ans;
    for(int cnt = 0; cnt < n; ++cnt) {
        ans.push_back(s.substr(i, lengths[cnt]));
        i += lengths[cnt];
    }
    return ans;
}
