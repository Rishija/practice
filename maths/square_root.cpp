/*
 Implement int sqrt(int x). Compute and return the square root of x. x is guaranteed to be a non-negative integer
 */
/*
 Time : O(lg N)
 Space : O(1)
 */
#include <iostream>
using namespace std;
int sqrt(int n) {
    
    if(n == 1)
        return 1;
    
    int low = 2, high = n / 2, mid, temp;
    while(low <= high) {
        
        mid = low + (high - low) / 2;
        temp = mid * mid;
        if(temp == n)
            return mid;
        if(temp < n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low - 1;
}

int main() {
    
    for(int i = 1; i <= 100; ++i)
        cout << i << "\t:\t" << sqrt(i) << endl;
    return 0;
}
