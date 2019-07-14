/*
You have N bulbs in a row numbered from 1 to N. Initially, all the bulbs are turned off. We turn on exactly one bulb everyday until all bulbs are on after N days.

You are given an array bulbs of length N where bulbs[i] = x means that on the (i+1)th day, we will turn on the bulb at position x where i is 0-indexed and x is 1-indexed.

Given an integer K, find out the minimum day number such that there exists two turned on bulbs that have exactly K bulbs between them that are all turned off.

If there isn't such day, return -1.

Example 1:

Input:
bulbs: [1,3,2]
K: 1
Output: 2
Explanation:
On the first day: bulbs[0] = 1, first bulb is turned on: [1,0,0]
On the second day: bulbs[1] = 3, third bulb is turned on: [1,0,1]
On the third day: bulbs[2] = 2, second bulb is turned on: [1,1,1]
We return 2 because on the second day, there were two on bulbs with one off bulb between them.

Example 2:

Input:
bulbs: [1,2,3]
K: 1
Output: -1


Note:

1 <= N <= 20000
1 <= bulbs[i] <= N
bulbs is a permutation of numbers from 1 to N.
0 <= K <= 20000
*/

int kEmptySlots(vector<int>& bulbs, int K) {
    int n = bulbs.size();
    vector<myData> v(n);
    for(int i = 0; i < n; ++i) {
        int bulb = bulbs[i] - 1;
        setLeftAndRight(v, bulb);
        int left = v[bulb].left;
        if(left != -1 && (bulb - left - 1) == K)
            return i + 1;
        int right = v[bulb].right;
        if(right != n && (right - bulb - 1) == K)
            return i + 1;
    }
    return -1;
}

void setLeftAndRight(vector<myData> &v, int bulb) {
    int i;
    for(i = bulb - 1; i >= 0 && !v[i].val1; --i)
        v[i].right = bulb;

    if(i >= 0)
        v[i].right = bulb;
    v[bulb].left = i;

    for(i = bulb + 1; i < v.size() && !v[i].val1; ++i)
        v[i].left = bulb;

    if(i < v.size())
        v[i].left = bulb;
    v[bulb].right = i;

    v[bulb].val1 = true;
}
