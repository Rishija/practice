#include <iostream>
#include <string>
using namespace std;

/*
 Time : O(n)
 Space : O(1)
 */
bool isValid(string s) {
    
    if(s.size() < 1)
        return true;
    
    int count = 0;
    for(char ch : s) {
        if(ch == '(')
            ++ count;
        else if(ch == ')')
            -- count;
        
        if(count < 0)
            return false;
    }
    return count == 0;
}
