/*
 There are a total of n courses you have to take, labeled from 0 to n-1.
 
 Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 
 Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
 
 There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
 */

typedef vector<int> vi;
typedef vector<vi> vvi;
enum Status {UNVISITED, VISITED, INPROCESS};

bool ifCycle(const vvi &graph, vi &status, const int n, const int current, vi &order) {
    
    bool ans;
    status[current] = INPROCESS;
    for(int node : graph[current]) {
        if(status[node] == INPROCESS)
            return false;
        if(status[node] == VISITED)
            continue;
        status[node] = INPROCESS;
        ans = ifCycle(graph, status, n, node, order);
        if(ans == false)
            return false;
        status[node] = VISITED;
    }
    order.insert(order.begin(), current);
    return true;
}

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    
    if(numCourses == 0)
        return {};
    if(numCourses == 1)
        return {0};
    
    vvi graph(numCourses);
    for(auto p : prerequisites)
        graph[p.second].push_back(p.first);
    vi status(numCourses, UNVISITED), order;
    bool ans;
    
    for(int i = 0; i < numCourses; ++i) {
        if(status[i] == UNVISITED) {
            ans = ifCycle(graph, status, numCourses, i, order);
            if(ans == false)
                return {};
        }
        status[i] = VISITED;
    }
    return order;
}
