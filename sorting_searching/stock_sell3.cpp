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

class collection {
public:
    int min;
    int maxx;
    int profit;
    collection() : min(0), maxx(0), profit(0) {}
};

int maxProfit(vector<int> prices) {
    
    int n = prices.size();
    
    if(n < 2)
        return 0;
    
    if(n == 2)
        return prices[1] > prices[0] ? prices[1] - prices[0] : 0;
    
    vector<collection>leftProfit(n), rightProfit(n);
    leftProfit[0].min = prices[0];
    rightProfit[n-1].maxx = prices[n-1];
    
    for(int i = 1; i < n; ++i) {
        leftProfit[i].min = min(leftProfit[i-1].min, prices[i]);
        leftProfit[i].profit = max(leftProfit[i-1].profit, prices[i] - leftProfit[i].min);
    }
    
    for(int i = n - 2; i >= 0 ; --i) {
        rightProfit[i].maxx = max(rightProfit[i+1].maxx, prices[i]);
        rightProfit[i].profit = max(rightProfit[i+1].profit, rightProfit[i].maxx - prices[i]);
    }
    
    int maxx = max1(prices, 0, n);
    
    for(int i = 0; i < n - 1; ++i)
        maxx = max(maxx, leftProfit[i].profit + rightProfit[i+1].profit);
    
    return maxx;
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
