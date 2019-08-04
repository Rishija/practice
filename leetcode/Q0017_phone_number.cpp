/*
 Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 */
/*
 Time: Exponential
 Space: O(n) - n is length of string
 */

void helper(const string &digits, const int &n, string &temp, int index, vector<string> &ans, const map<int, string>& hash) {
    
    if(index == n) {
        ans.push_back(temp);
        return;
    }
    
    for(int i = 0; i < hash.at((int)(digits[index]) - 48).size(); ++i) {
        temp[index] = hash.at((int)(digits[index]) - 48)[i];
        helper(digits, n, temp, index + 1, ans, hash);
    }
}


vector<string> letterCombinations(string digits) {
    int n = digits.size();
    if(n == 0)
        return {};
    map<int, string> hash;
    hash[2] = "abc"; hash[3] = "def"; hash[4] = "ghi"; hash[5] = "jkl";
    hash[6] = "mno"; hash[7] = "pqrs"; hash[8] = "tuv"; hash[9] = "wxyz";
    
    string temp(n, '\0');
    vector<string> ans;
    helper(digits, n, temp, 0, ans, hash);
    return ans;
}
