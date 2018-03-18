/*
 Given an array of meeting time intervals consisting of start and end times
 [[s1,e1],[s2,e2],...]
 Find the minimum number of conference rooms required
 */
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Interval {
public:
    int start, end;
    Interval() : start(0), end(0) {}
    Interval(int s,int e) : start(s), end(e) {}
};

int conference_room1(vector<Interval> vec) {
    
    int n = (int)vec.size();
    if(!n)
        return 0;
    if(n == 1)
        return 1;
    
    sort(vec.begin(), vec.end(), [] (const Interval &a, const Interval &b) {
        if(a.end < b.end)
            return true;
        if(a.end == b.end)
            return a.start < b.start;
        return false;
    });
    
    int counter = 0, currentIndex = 1, rooms = 1;
    while(currentIndex < n) {
        while(vec[counter].end <= vec[currentIndex].start)
            ++ counter;
        rooms = max(rooms, currentIndex - counter + 1);
        ++ currentIndex;
    }
    
    return rooms;
}

int conference_room2(vector<Interval> vec) {
    
    int n = (int)vec.size();
    if(!n)
        return 0;
    if(n == 1)
        return 1;
    
    /*
     Second parameter of pair tells whether its start or end time
     0 - start
     1 - end
     */
    vector<pair<int,bool> > all;
    
    for(int i = 0; i < n; ++i) {
        all.push_back({vec[i].start,0});
        all.push_back({vec[i].end,1});
    }
    
    sort(all.begin(), all.end(), [] (const pair<int,bool> &a, const pair<int,bool> &b) {
        if(a.first < b.first)
            return true;
        /*
         Put end time first in case of collision of points
         Ex: [1 3] and [3 10]
         */
        if(a.first == b.first)
            return a.second;
        return false;
    });
    
    int rooms = 1, counter = 0;
    for(int i = 0; i < all.size(); ++i) {
        if(all[i].second)
            -- counter;
        else
            ++ counter;
        rooms = max(rooms, counter);
    }
    
    return rooms;
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
    
    cout << conference_room1(vec) << endl;
    cout << conference_room2(vec) << endl << endl;
}

int main() {
    
    vector<int> start = {0,5,15}, end = {30,10,20};
    room_print(start, end);
    
    start = {1,2}; end = {2,10};
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
    
    start = {1,2,5}; end = {4,8,9};
    room_print(start, end);
    
    start = {1,2,3,5}; end = {4,7,6,10};
    room_print(start, end);
    
    return 0;
}
