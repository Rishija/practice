/*
 Given N nuts and N bolts. There is 1:1 mapping between nuts and bolts. You can't compare nut with other nuts or bolt with bolt. But you can compare nut with bolt. When you compare a nut with bolt you get a result saying 1) if nut is bigger 2) if bolt is bigger 3) if they match. Match each nut with bolt.
 */
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    
    int temp = a;
    a = b;
    b = temp;
}

/* Brute Force
 
 Complexity : O(n^2)
 
void match(char *nuts, int *bolts, int n) {
    
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            if(bolts[j] == static_cast<int>(nuts[i])) {
                swap(bolts[i], bolts[j]);
                break;
            }
        }
    }
}

int main() {
    
    char nuts[10] = {'g', 'a', 'j', 'd', 'e', 'c', 'h', 'f', 'b', 'i'};
    int bolts[10] = {106, 100, 98, 97, 101, 104, 105, 100, 103, 102};
    
    match(nuts, bolts, 10);
    
    for(int i = 0; i < 10; ++i) {
        cout << nuts[i] << " -> " << bolts[i] << endl;
    }
    
    return 0;
}
*/


/* Using Quicksort
 
 Complexity : Average - O(n lgn)
              Worst - O(n^2)
 */
int partition(vector<int> &arr, int start, int end, int comp) {
    
    -- start;
    
    for(int i = start + 1; i < end; ++i) {
        
        if(arr[i] < comp)
            swap(arr[++start],arr[i]);
        else if(arr[i] == comp) {
            swap(arr[end], arr[i]);
            -- i;
        }
    }
    swap(arr[end], arr[++start]);
    return start;
}

void mapp(vector<int> &nuts, vector<int> &bolts, int start, int end) {
    
    if(start >= end)
        return;
    
    int index = partition(nuts, start, end, bolts[end]);
    partition(bolts, start, end, nuts[index]);
    
    mapp(nuts, bolts, start, index - 1);
    mapp(nuts, bolts, index + 1, end);
    
}

bool nuts_bolts(vector<int> &nuts, vector<int> &bolts) {
    
    int n = nuts.size(), m = bolts.size();
    
    if(n != m)
        return false;
    
    if(n < 2)
        return true;
    
    mapp(nuts, bolts, 0, n - 1);
    return true;
}

void map_print(vector<int> &a, vector<int> &b) {
    
    if(!nuts_bolts(a, b))
        return;
    
    for(int i = 0; i < a.size(); ++i)
        cout << a[i] << " -> " << b[i] << endl;
    cout << endl;
}

int main() {
    
    vector<int> nuts = {6,1,8,9,2,4,10,3,7,5}, bolts = {10,9,8,7,6,5,4,3,2,1};
    map_print(nuts, bolts);
    
    nuts = {1,2}; bolts = {1,2};
    map_print(nuts, bolts);
    
    nuts = {1,2}; bolts = {2,1};
    map_print(nuts, bolts);
    
    nuts = {1,2,3}; bolts = {3,2,1};
    map_print(nuts, bolts);
    
    nuts = {4,3,2,1}; bolts = {1,2,3,4};
    map_print(nuts, bolts);
    
    nuts = {8,3,2,7,5,1,4,6}; bolts = {3,5,7,1,8,4,2,6};
    map_print(nuts, bolts);
    
    nuts = {1}; bolts = {1};
    map_print(nuts, bolts);
    
    return 0;
}
