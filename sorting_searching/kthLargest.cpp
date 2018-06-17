/*
 Find kth largest element in a stream of input
 On every call to add(), return the required element
 */

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> collection;
public:
    int k;
    KthLargest(int k, vector<int> nums): k(k) {
        for(auto ele : nums)
            add(ele);
    }
    int add(int val) {
        if(collection.size() < k)
            collection.push(val);
        else if(collection.top() <= val) {
            collection.push(val);
            collection.pop();
        }
        return collection.top();
    }
};

