/*
 Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
 */

bool backspaceCompare(string S, string T) {
    
    int n = S.size(), m = T.size();
    if(n == 0 && m == 0)
        return true;
    string a(n,'\0'), b(m, '\0');
    
    int i = 0, j = 0;
    for(int k = 0; k < n; ++k) {
        if(S[k] != '#') {
            if(i < 0)   i = 0;
            a[i++] = S[k];
        }
        else
            --i;
    }
    for(int k = 0; k < m; ++k) {
        if(T[k] != '#') {
            if(j < 0)   j = 0;
            b[j++] = T[k];
        }
        else
            --j;
    }
    
    if(j < 0)   j = 0;
    if(i < 0)   i = 0;
    return a.substr(0, i) == b.substr(0, j);
}
