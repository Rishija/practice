#include <iostream>
#include <vector>
using namespace std;

class Interval {
public:
    int start, end;
    Interval() : start(0), end(0) {}
    Interval(int s,int e) : start(s), end(e) {}
};

vector<Interval> merge_overlapping(vector<Interval> vec) {
    
    int n = vec.size(), i = 0;
    vector<Interval> ans;
    if(!n)
        return ans;
    
    sort(vec.begin(), vec.end(), [] (const Interval &a, const Interval &b) {
        if(a.start < b.start)
            return true;
        if(a.start == b.start)
            return a.end < b.end;
        return false;
    });
    
    while(i < n) {
        int start = vec[i].start, max = vec[i].end;
        while(i < n && vec[i].start <= max) {
            max = vec[i].end > max ? vec[i].end : max;
            ++i;
        }
        Interval x(start, max);
        ans.push_back(x);
    }
    return ans;
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
    vec = merge_overlapping(vec);
    for(int i = 0; i < vec.size(); ++i)
        cout << "[" << vec[i].start << " " << vec[i].end << "] ";
    cout << endl;
}

int main() {
    
    vector<int> start = {1,3,8,15}, end = {3,6,10,18};
    merge_print(start, end);
    
    start = {1, 2}; end = {10, 5};
    merge_print(start, end);
    
    start = {4}; end = {5};
    merge_print(start, end);
    
    start = {9,3,40,32,19}; end = {10,20,41,50,25};
    merge_print(start, end);
    
    start = {10,2}; end = {12,11};
    merge_print(start, end);
   
    return 0;
}
