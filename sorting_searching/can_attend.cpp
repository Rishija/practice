#include <iostream>
#include <vector>
using namespace std;

class Interval {
public:
    int start, end;
    Interval() : start(0), end(0) {}
    Interval(int s,int e) : start(s), end(e) {}
};

bool can_attend(vector<Interval> vec) {
    
    int n = vec.size(), i = 0;
    if(n < 2)
        return true;
    
    sort(vec.begin(), vec.end(), [] (const Interval &a, const Interval &b) {
        if(a.start < b.start)
            return true;
        if(a.start == b.start)
            return a.end < b.end;
        return false;
    });
    
    int end = vec[0].end;
    for(int i = 1; i < n; ++i) {
        
        if(vec[i].end <= end)
            return false;
        
        end = vec[i].end;
    }
    return true;
}


void merge_print(const vector<int> &a, const vector<int> &b) {
    
    if(a.size() != b.size())
        exit(1);
    
    vector<Interval> vec;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] > b[i])
            exit(1);
        
        Interval temp(a[i], b[i]);
        vec.push_back(temp);
    }
    
    cout << can_attend(vec) << endl;
}

int main() {
    
    vector<int> start = {0,5,15}, end = {30,10,20};
    merge_print(start, end);
    
    start = {1,2}; end = {10, 5};
    merge_print(start, end);
    
    start = {1,2}; end = {5,10};
    merge_print(start, end);
    
    start = {1,5,10,15}; end = {3,6,18,20};
    merge_print(start, end);
    
    start = {4}; end = {6};
    merge_print(start, end);
    
    return 0;
}
