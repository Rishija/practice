/*
 Check if given positive number is a perfect square
 */
/*
 Time : O(lg N)
 Space : O(1)
 */
#include <iostream>
using namespace std;

bool isPerfectSqaure(int n) {
    
    if(n == 1)
        return true;
    
    int low = 2, high = n / 2, mid, temp;
    while(low <= high) {
        
        mid = low + (high - low) / 2;
        temp = mid * mid;
        if(temp == n)
            return true;
        if(temp < n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    
    for(int i = 1; i <= 100; ++i)
        cout << i << "\t:\t" << isPerfectSqaure(i) << endl;
    return 0;
}
