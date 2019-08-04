/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
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
    
    int minIndex = 0, maxIndex = 0, profit = 0;
    
    
    for(int i = 1; i < n; ++i) {
        
        if(prices[i] < prices[minIndex])
            minIndex = i;
        
        if(i > minIndex && prices[i] - prices[minIndex] > profit) {
            maxIndex = i;
            profit = prices[i] - prices[minIndex];
        }
    }
    
    return profit;
    
    /* Method 2
     
     int min = prices[0], profit = 0;
     
     for(int i = 1; i < n; ++i) {
     
     if(prices[i] - min > profit) {
     profit = prices[i] - min;
     }
     min = prices[i] < min ? prices[i] : min;
     }
     
     return profit;
     */
}

int main() {
    
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(v) << endl;
    
    v = {7, 6, 4, 3, 1};
    cout << maxProfit(v) << endl;
}

