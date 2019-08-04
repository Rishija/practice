/*
 Given an input string , reverse the string word by word.
 
 Example:
 
 Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
 Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
 
 Note:
 
 A word is defined as a sequence of non-space characters.
 The input string does not contain leading or trailing spaces.
 The words are always separated by a single space.
 
 Follow up: Could you do it in-place without allocating extra space?
 */

void reverseWords(vector<char>& A) {
    int n = A.size();
    if(n < 3)   return;
    
    // Reverse string before or after reversing each word
    reverse(A.begin(), A.end());
    auto it = A.begin();
    while(it < A.end()) {
        //Find next word
        auto j = it;
        while(j != A.end() && *j != ' ')    ++j;
        //Reverse this word (includes `space`)
        reverse(it, j);
        // Set `it` to start of new word
        it = j + 1;
    }
    // reverse(A.begin(), A.end());
}
