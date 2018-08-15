/*
 There is a fence with n posts, each post can be painted with one of the k colors.
 
 You have to paint all the posts such that no more than two adjacent fence posts have the same color.
 
 Return the total number of ways you can paint the fence.
 
 Note:
 n and k are non-negative integers.
 
 Example:
     Input: n = 3, k = 2
     Output: 6
 Explanation: Take c1 as color 1, c2 as color 2. All possible ways are:
 
 post1  post2  post3
 -----      -----  -----  -----
 1         c1     c1     c2
 2         c1     c2     c1
 3         c1     c2     c2
 4         c2     c1     c1
 5         c2     c1     c2
 6         c2     c2     c1
 */

int numWays(int n, int k) {
    if(n == 0)  return 0;
    if(n == 1)  return k;
    if(k == 1)  return n > 2 ? 0 : 1;
    
    int same = k, diff = k * (k-1);
    for(int i = 2; i < n; ++i) {
        /**
         ASSIGN SAME
         * When previous's last 2 colors are different, how can current's last 2 have same color?
         * By assinging same color to last post as of second last post
         * Therefore current same = last different
         */
        int lastSame = same;
        same = diff;
        
        /*
         ASSIGN DIFFERENT
         * Different color in current's last 2 can be constructed in 2 ways
         FROM SAME
         * Assign different color from second last post
         * ie., (k-1) options for last post
         FROM DIFFERENT
         * Assign different color from second last post
         * ie., (k-1) options for last post
         
         */
        diff = (lastSame + diff) * (k-1);
    }
    // Return total
    return same + diff;
}
