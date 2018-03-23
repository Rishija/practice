#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 Brute force
 Time : O(n^2)
 Space : O(1)
 */
int largest_histogram1(vector<int> &graph) {
    
    int n = graph.size();
    
    if(!n)
        return 0;
    if(n == 1)
        return graph[0];
    
    int maxx = 0;
    
    for(int i = 0; i < n; ++i) {
        
        int j = i - 1, k = i + 1;
        while(j >= 0 && graph[j] >= graph[i])
            --j;
        while(k < n && graph[k] >= graph[i])
            ++k;
        ++j;
        maxx = max(maxx, graph[i] * (k - j));
    }
    return maxx;
}

/*
 Time : O(n)
 Space : O(n)
 */
int largest_histogram2(vector<int> &graph) {
    
    int n = graph.size();
    
    if(!n)
        return 0;
    if(n == 1)
        return graph[0];
    
    int maxx = 0, i = 0;
    stack<int> bounds;
    
    while(i < n) {
        
        // Push larger elements
        if(bounds.empty() || graph[bounds.top()] <= graph[i]) {
            bounds.push(i);
            ++i;
            continue;
        }
        
        // Single element with lowest value till index `i`
        if(bounds.size() == 1) {
            maxx = max(maxx, graph[bounds.top()] * i);
            bounds.pop();
        }
        else {
            int temp = bounds.top();
            bounds.pop();
            // bounds.top() is the lower limit, `i` is the upper limit for temp
            maxx = max(maxx, graph[temp] * (i - bounds.top() - 1));
        }
    }
    
    while (!bounds.empty()){
        
        int temp = bounds.top();
        bounds.pop();
        
        int tempArea = graph[temp] * (bounds.empty() ? i : i - bounds.top() - 1);
        maxx = max(maxx, tempArea);
    }
    
    return maxx;
}

int main() {
    
    vector<int> v = {2, 3, 10};     // 10
    cout << largest_histogram1(v) << endl;
    cout << largest_histogram2(v) << endl << endl;
    
    v = {2, 3, 4};                  // 6
    cout << largest_histogram1(v) << endl;
    cout << largest_histogram2(v) << endl << endl;
    
    v = {9, 2, 6, 10, 6, 5};        // 20
    cout << largest_histogram1(v) << endl;
    cout << largest_histogram2(v) << endl << endl;
    
    v = {6, 2, 5, 4, 5, 1, 6};      // 12
    cout << largest_histogram1(v) << endl;
    cout << largest_histogram2(v) << endl << endl;
    
    v = {2, 1, 5, 6, 2, 3};         // 10
    cout << largest_histogram1(v) << endl;
    cout << largest_histogram2(v) << endl << endl;
    
    return 0;
}

