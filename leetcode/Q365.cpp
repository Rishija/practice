/*
 You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

 If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

 Operations allowed:

 Fill any of the jugs completely with water.
 Empty any of the jugs.
 Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
 Example 1: (From the famous "Die Hard" example)

 Input: x = 3, y = 5, z = 4
 Output: True
 Example 2:

 Input: x = 2, y = 6, z = 5
 Output: False
 */

int gcd(int a, int b){

    if (a == 0 || b == 0)
        return 0;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {

        if(z > (x + y))
            return false;
        if(z == (x + y))
            return true;
        if(x == 0) {
            if(y == 0)
                return z ? false : true;
            return z % y ? false : true;
        }
        if(y == 0)
            return z % x ? false : true;

        return z % gcd(x,y) ? false : true;
    }
};
