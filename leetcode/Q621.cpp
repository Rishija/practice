/*
 Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

 However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

 You need to return the least number of intervals the CPU will take to finish all the given tasks.

 Example 1:
 Input: tasks = ["A","A","A","B","B","B"], n = 2
 Output: 8
 Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 Note:
 The number of tasks is in the range [1, 10000].
 The integer n is in the range [0, 100].
 */

struct info {
    char alpha;
    int index;
    int cnt;
    info(char alpha, int index, int cnt) : alpha(alpha), index(index), cnt(cnt) {}
};
class cmp {
public:
    bool operator() (const info &a, const info &b) {
        return a.cnt < b.cnt;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int K) {
        unordered_map<char, int> map;
        for(char &a : tasks) ++map[a];

        int ans = 0;
        priority_queue<int> pq;
        for(auto p : map) pq.push(p.second);

        while(!pq.empty()) {
            vector<int> toPush;
            for(int gap = 0; gap <= K; ++gap) {
                if(!pq.empty()) {
                    int top = pq.top(); pq.pop();
                    --top;
                    if(top > 0)  toPush.push_back(top);
                }
                ++ans;
                if(toPush.empty()) break;
            }
            for(auto val : toPush) pq.push(val);
        }
        return ans;
        // return helper1(tasks, K);
        // return helper2(tasks, K);
    }
    int helper1(vector<char> &tasks, int K) {
        if(tasks.empty())   return 0;
        if(K == 0)          return tasks.size();
        unordered_map<char, int> map;
        for(char &a : tasks) ++map[a];

        int ans = 0;
        vector<char> mark(1);
        priority_queue<info, vector<info>, cmp> pq;
        // `index` points last index where this alphabet was inserted
        for(auto p : map) pq.push({p.first, -(K + 1), p.second});

        while(!pq.empty()) {
            auto current = pq.top(); pq.pop();
            int i = current.index + K + 1;  // Start searching from valid index
            // Search until an empty place is found
            while(true) {
                if(i >= mark.size()) mark.resize(i+1);
                if(mark[i] == '\0') {
                    if(i > ans)  ans = i;
                    mark[i] = current.alpha;
                    current.index = i;
                    --current.cnt;
                    if(current.cnt > 0) pq.push(current);
                    break;
                }
                ++i;
            }
        }
        return ans + 1;
    }

    int helper2(vector<char> &tasks, int K) {
        if(tasks.empty())   return 0;
        if(K == 0)          return tasks.size();
        unordered_map<char, int> map;
        for(char &a : tasks) ++map[a];

        int ans = 0;
        vector<char> mark(1);
        priority_queue<info, vector<info>, cmp> pq;
        for(auto &p : map) pq.push({p.first, -(K + 1), p.second});
        pq.push({'x', -10, 0});

        while(pq.size() > 1) {
            auto current = pq.top(); pq.pop();
            int toAllot = (pq.top().cnt == current.cnt) ? 1 : current.cnt - pq.top().cnt;
            current.cnt -= toAllot;
            while(toAllot--) {
                int i = current.index + K + 1;
                if(i >= mark.size()) mark.resize(i+1);
                while(mark[i] != '\0') {
                    ++i;
                    if(i >= mark.size()) mark.resize(i+1);
                }
                mark[i] = current.alpha;
                current.index = i;
                if(i > ans) ans = i;
            }
            if(current.cnt > 0) pq.push(current);
        }
        return ans + 1;
    }
};
