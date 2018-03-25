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

int trap(vector<int>& height) {
    
    int n = height.size();
    if(n < 2)
        return 0;
    
    // chop 0 from starting
    int start = 0;
    while(start < n && height[start] == 0)
        ++ start;
    
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

int main() {
    
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(v) << endl;
    
    v = {4,2,3};
    cout << trap(v) << endl;
    return 0;
}
