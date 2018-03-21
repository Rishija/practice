/*
 Check is a given number is power of 2. Number may exceed range of int or long
 */
/*
 Time : O(lg N)     N -> number
 Space : O(d)       d -> number of digits in number
 */
#include <iostream>
using namespace std;

string chop0(string s) {
    
    int n = s.size(), i = 0;
    while(i < n && s[i] == '0')
        ++ i;
    return s.substr(i);
}

int power(string A) {
    
    int n = (int)A.size();
    
    if(A[n-1]!='2' && A[n-1]!='4' && A[n-1]!='6' && A[n-1]!='8')
        return 0;
    
    while(true) {
        
        string temp, prev = "", quo = "";
        int i = 0, num;
        n = A.size();
        
        while(i < n) {
            temp = "";
            temp += prev + A[i];
            num = stoi(temp);
            while(num < 2 && (i+1) < n) {
                quo += "0";
                temp += A[++i];
                num = stoi(temp);
            }
            quo += to_string(num / 2);
            prev = to_string(num % 2);
            ++i;
        }
        
        quo = chop0(quo);
        
        if(prev == "1" && quo != "")
            return false;
        
        if(quo == "" || quo == "1" && prev == "0")
            return true;
        
        A = quo;
    }
    return true;
}

int main() {
    
    string a;
    
    // no
    a = "1";
    cout << a << ": " << power(a) << endl;
    
    a = "8196";
    cout << a << ": " << power(a) << endl;
    
    a = "6";
    cout << a << ": " << power(a) << endl;
    
    a = "18";
    cout << a << ": " << power(a) << endl;
    
    a = "68";
    cout << a << ": " << power(a) << endl;
    
    a = "252";
    cout << a << ": " << power(a) << endl;
    
    a = "32762";
    cout << a << ": " << power(a) << endl;
    
    a = "524286";
    cout << a << ": " << power(a) << endl;
    
    a = "4194308";
    cout << a << ": " << power(a) << endl;
    
    a = "1099511627774";
    cout << a << ": " << power(a) << endl;
    
    a = "1125899906842621";
    cout << a << ": " << power(a) << endl;
    
    a = "18889465931478580854788";
    cout << a << ": " << power(a) << endl;
    
    a = "680564733841876926926749214863536422914";
    cout << a << ": " << power(a) << endl;
    
    // yes
    a = "2";
    cout << a << ": " << power(a) << endl;
    
    a = "4";
    cout << a << ": " << power(a) << endl;
    
    a = "16";
    cout << a << ": " << power(a) << endl;
    
    a = "64";
    cout << a << ": " << power(a) << endl;
    
    a = "256";
    cout << a << ": " << power(a) << endl;
    
    a = "8192";
    cout << a << ": " << power(a) << endl;
    
    a = "32768";
    cout << a << ": " << power(a) << endl;
    
    a = "524288";
    cout << a << ": " << power(a) << endl;
    
    a = "4194304";
    cout << a << ": " << power(a) << endl;
    
    a = "1099511627776";
    cout << a << ": " << power(a) << endl;
    
    a = "1125899906842624";
    cout << a << ": " << power(a) << endl;
    
    a = "18889465931478580854784";
    cout << a << ": " << power(a) << endl;
    
    a = "680564733841876926926749214863536422912";
    cout << a << ": " << power(a) << endl;
    
    return 0;
}

