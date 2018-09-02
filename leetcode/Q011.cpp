/*
 Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 
 Note: You may not slant the container and n is at least 2.

 Example:
 
 Input: [1,8,6,2,5,4,8,3,7]
 Output: 49
 */

int maxArea(vector<int>& height) {
    
    int n = (int)height.size();
    if(n < 2)
        return 0;
    long long ans = 0;
    
    long long int low = 0, high = n-1;
    while(low < high) {
        
        if(height[low] < height[high]) {
            ans = max(ans, height[low]*(high - low));
            ++low;
        }
        else {
            ans = max(ans, height[high]*(high - low));
            --high;
        }
    }
    return ans;
}
