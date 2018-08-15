/*
 Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.
*/

int lengthOfLongestSubstringTwoDistinct(string s) {
    int n = s.size();
    if(n < 2)   return n;
    
    char first = NULL, second = NULL;
    int i = 0, j = 0, maxx = 0, fPos = -1, sPos = -1;
    
    while(j < n) {
        if(first == NULL) {
            first = s[j];
            fPos = j;
        }
        else if(second == NULL && s[j] != first) {
            second = s[j];
            sPos = j;
        }
        else if(s[j] == first)  fPos = j;
        else if(s[j] == second) sPos = j;
        
        else if(s[j] != first && s[j] != second) {
            if(fPos < sPos) {
                i = fPos + 1;
                first = s[j];
                fPos = j;
            }
            else {
                i = sPos + 1;
                second = s[j];
                sPos = j;
            }
        }
        ++j;
        maxx = max(maxx, j - i);
    }
    return maxx;
}
