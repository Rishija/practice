/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class info {
public:
    vector<NestedInteger>::iterator current, last;
    info(vector<NestedInteger>::iterator c, vector<NestedInteger>::iterator l) : current(c), last(l) {}
};

class NestedIterator {
public:
    stack<info> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push({nestedList.begin(), nestedList.end()});
    }
    
    int next() {
        int val = s.top().current->getInteger();
        ++(s.top().current);
        return val;
        /* Doesn't covers case when begin() == end() initially
         
         while(s.top().current->isInteger() == false) {
         auto next = s.top().current->getList();
         s.push({next.begin(), next.end()});
         }
         int val = s.top().current->getInteger();
         s.top().current++;
         return val;
         */
    }
    
    bool hasNext() {
        while(!s.empty()) {
            if(s.top().current == s.top().last) {
                s.pop();
                continue;
            }
            if(s.top().current->isInteger())    return true;
            auto &next = s.top().current->getList();
            ++s.top().current;
            s.push({next.begin(), next.end()});
        }
        return false;
        /*
         while(!s.empty() && s.top().current == s.top().last) s.pop();
         return s.size() > 0;
         */
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
