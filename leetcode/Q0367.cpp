/*
 Given a positive integer num, write a function which returns True if num is a perfect square else False.

 Note: Do not use any built-in library function such as sqrt.

 Example 1:

 Input: 16
 Output: true
 Example 2:

 Input: 14
 Output: false
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 0)
            return false;

        if(num == 1)
            return true;

        int low = 2, high = num / 2, mid, temp;
        while(low <= high) {

            mid = low + (high - low) / 2;
            if(mid * mid == num)
                return true;
            if(mid < (num / mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};
