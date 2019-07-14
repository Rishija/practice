/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:

Input:
asteroids = [5, 10, -5]
Output: [5, 10]
Explanation:
The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.

Example 2:

Input:
asteroids = [8, -8]
Output: []
Explanation:
The 8 and -8 collide exploding each other.
Example 3:

Input:
asteroids = [10, 2, -5]
Output: [10]
Explanation:
The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in 10.
Example 4:

Input:
asteroids = [-2, -1, 1, 2]
Output: [-2, -1, 1, 2]
Explanation:
The -2 and -1 are moving left, while the 1 and 2 are moving right.
Asteroids moving the same direction never meet, so no asteroids will meet each other.
Note:

The length of asteroids will be at most 10000.
Each asteroid will be a non-zero integer in the range [-1000, 1000]..
*/

public int[] asteroidCollision(int[] A) {
    if(A == null || A.length == 1) return A;
    LinkedList<Integer> l = new LinkedList<Integer>();
    for(int x : A) l.add(Integer.valueOf(x));

    boolean done = false;
    do {
        done = false;
        for(int i = 0; i < l.size() - 1 && i >= 0; ++i) {
            int e1 = l.get(i).intValue(), e2 = l.get(i + 1).intValue();
            if(e1 > 0 && e2 < 0) {
                done = true;
                if(Math.abs(e1) > Math.abs(e2))
                    l.remove(i + 1);
                else if(Math.abs(e1) < Math.abs(e2))
                    l.remove(i);
                else {
                    l.remove(i);
                    l.remove(i);
                    --i;
                }
                --i;
            }
        }
    } while(done == true);
    return l.stream().mapToInt(x -> x).toArray();
}
