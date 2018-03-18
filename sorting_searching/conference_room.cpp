/*
 Given an array of meeting time intervals consisting of start and end times
 [[s1,e1],[s2,e2],...]
 Find the minimum number of conference rooms required
 */
#include <iostream>
#include <vector>
using namespace std;

class Interval {
public:
    int start, end;
    Interval() : start(0), end(0) {}
    Interval(int s,int e) : start(s), end(e) {}
};

int conference_room(vector<Interval> vec) {
    
    
    int n = vec.size();
    if(!n)
        return 0;
    if(n == 1)
        return 1;
    
    sort(vec.begin(), vec.end(), [] (const Interval &a, const Interval &b) {
        if(a.start < b.start)
            return true;
        if(a.start == b.start)
            return a.end < b.end;
        return false;
    });
    
    int start = vec[0].start, end = vec[0].end, i = 1, max = 1;
    while(i < n) {
        int cnt = 1;
        while(i < n && vec[i].start < end) {
            end = vec[i].end;
            ++ i;
            ++ cnt;
        }
        max = cnt > max ? cnt : max;
        end = vec[i].end;
        ++i;
    }
    
    return max;
}


void room_print(const vector<int> &a, const vector<int> &b) {
    
    if(a.size() != b.size())
        exit(1);
    
    vector<Interval> vec;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] > b[i])
            exit(1);
        
        Interval temp(a[i], b[i]);
        vec.push_back(temp);
    }
    
    cout << conference_room(vec) << endl;
}

int main() {
    
    vector<int> start = {0,5,15}, end = {30,10,20};
    room_print(start, end);
    
    start = {1,7}; end = {5,10};
    room_print(start, end);
    
    start = {1,2}; end = {5,10};
    room_print(start, end);
    
    start = {2,1,3}; end = {8,30,5};
    room_print(start, end);
    
    start = {1,2}; end = {10, 5};
    room_print(start, end);
    
    start = {1,5,10,15}; end = {3,6,18,20};
    room_print(start, end);
    
    start = {4}; end = {6};
    room_print(start, end);
    
    return 0;
}
