/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 */
/*
 Time : O(n)
 Space : O(n)
 */
#include <iostream>
#include <vector>
using namespace std;

int max1(vector<int>& prices, int start, int end) {
    
    if((end - start) < 2)
        return 0;
    
    int min = prices[start], profit = 0;
    
    for(int i = start + 1; i < end; ++i) {
        
        if(prices[i] - min > profit)
            profit = prices[i] - min;
        min = prices[i] < min ? prices[i] : min;
    }
    
    return profit;
}

int maxProfit(vector<int> prices) {
    
    int n = prices.size();
    
    if(n < 2)
        return 0;
    
    if(n == 2)
        return prices[1] > prices[0] ? prices[1] - prices[0] : 0;
    
    int minn, maxx;
    minn = prices[0];
    maxx = prices[n-1];
    vector<int>leftProfit(n,0), rightProfit(n,0);
    
    for(int i = 1; i < n; ++i) {
        
        minn = min(prices[i],minn);
        maxx = max(prices[n - i - 1], maxx);
        leftProfit[i] = max(leftProfit[i-1], prices[i] - minn);
        rightProfit[n - i - 1] = max(rightProfit[n - i], maxx - prices[n - i - 1]);
    }
    
    int maxProfit = max1(prices, 0, n);
    
    for(int i = 0; i < n - 1; ++i)
        maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i+1]);
    
    return maxProfit;
}

int main() {
    
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(v) << endl;
    
    v = {1,2,4};
    cout << maxProfit(v) << endl;
    
    v = {7, 6, 4, 3, 1};
    cout << maxProfit(v) << endl;
    
    v = {100, 180, 260, 310, 40, 535, 695};
    cout << maxProfit(v) << endl;
    
    v = {8, 1, 4, 7, 2, 9};
    cout << maxProfit(v) << endl;
    
    v = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    cout << maxProfit(v) << endl;
    
    return 0;
}
