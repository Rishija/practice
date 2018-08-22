/*
 Write a function to generate the generalized abbreviations of a word.
 
 Note: The order of the output does not matter.
 
 Example:
 
 Input: "word"
 Output:
 ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 */

void helper(vector<string> &ans, string current, const string &A, int index) {
    if(index == A.size()) {
        ans.push_back(current);
        return;
    }
    helper(ans, current + A[index], A, index + 1);
    int len = 1;
    while(index + len <= A.size()) {
        if(current.size() == 0 || !isdigit(current[current.size() - 1]))
            helper(ans, current + to_string(len), A, index + len);
        ++len;
    }
}

vector<string> generateAbbreviations(string A) {
    int n = A.size();
    vector<string> ans;
    helper(ans, "", A, 0);
    return ans;
}
