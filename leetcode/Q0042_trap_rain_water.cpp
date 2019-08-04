/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 */
/*
 Time : O(n)
 Space : O(n)
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trap1(vector<int>& height) {
    int n = height.size(); if(n < 3) return 0;
    
    // chop 0 from starting
    int start = 0;
    while(start < n && height[start] == 0) ++start;
    
    int sum = 0, temp;
    stack<int> stack;
    stack.push(INT_MAX);
    
    for(int i = start; i < n; i++) {
        int current = stack.top();
        while((current != INT_MAX) && (height[current] <= height[i])) {
            stack.pop();
            if(stack.top() == INT_MAX)
                temp = 0;
            else
                temp = (min(height[stack.top()], height[i]) - height[current]) * (i - stack.top() - 1);
            sum += temp;
            current = stack.top();
        }
        stack.push(i);
    }
    return sum;
}

/*
 Time : O(n)
 Space : O(1)
 */
int trap2(vector<int>& height) {
    int n = height.size(); if(n < 3) return 0;
    int ans = 0, i = 0, j = 1;
    
    while(j < n) {
        // Search until a stopping bar is found
        if(height[j] < height[i]) { ++j; continue; }
        int temp = height[i];
        /* corner bars are `i` and `j` with `i` being smaller bar
         For each bar between i and j, add (i - bar) in result */
        while(i < j) ans += temp - height[i++];
        j = i + 1;
    }
    
    /* Start the same procedure from back of the array,
     in case the largest bar is not the last bar */
    --j;
    int k = j - 1;
    while(k >= i) {
        if(height[k] < height[j]) { --k; continue; }
        int temp = height[j];
        while(j > k) ans += temp - height[j--];
        k = j - 1;
    }
    return ans;
}


int main() {
    
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap1(v) << endl;
    
    v = {4,2,3};
    cout << trap1(v) << endl;
    return 0;
}
