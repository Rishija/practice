/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
/*
 Time O(n)
 Space O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    
    int n = prices.size();
    
    if(n < 2)
        return 0;
    
    if(n == 2)
        return prices[1] > prices[0] ? prices[1] - prices[0] : 0;
    
    int min = prices[0], maxx = prices[0], maxTillNow = 0, profit = 0, i = 0;
    
    while(i < n) {
        
        if(prices[i] - min > maxTillNow) {
            maxTillNow = prices[i] - min;
            maxx = prices[i];
        }
        if(prices[i] < maxx) {
            min = prices[i];
            profit += maxTillNow;
            maxTillNow = 0;
        }
        ++ i;
    }
    profit += maxTillNow;
    return profit;
    
    /* Method 2
     Add all positive changes
     */
}

int main() {
    
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(v) << endl;
    
    v = {7, 6, 4, 3, 1};
    cout << maxProfit(v) << endl;
    
    v = {100, 180, 260, 310, 40, 535, 695};
    cout << maxProfit(v) << endl;
    
    v = {8, 1, 4, 7, 2, 9};
    cout << maxProfit(v) << endl;
    return 0;
}

