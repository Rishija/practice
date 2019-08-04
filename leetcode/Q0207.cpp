/*
 There are a total of n courses you have to take, labeled from 0 to n-1.
 
 Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 
 Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 */

typedef vector<int> vi;
typedef vector<vi> vvi;

enum Status {UNVISITED, VISITED, INPROCESS};

bool ifCycle(const vvi &graph, vi &status, const int n, const int current) {
    
    bool ans;
    status[current] = INPROCESS;
    for(int node : graph[current]) {
        if(status[node] == INPROCESS)
            return false;
        status[node] = INPROCESS;
        ans = ifCycle(graph, status, n, node);
        if(ans == false)
            return false;
        status[node] = VISITED;
    }
    return true;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    
    if(numCourses < 2)
        return true;
    
    vvi graph(numCourses);
    for(auto p : prerequisites)
        graph[p.second].push_back(p.first);
    vi status(numCourses, UNVISITED);
    bool ans;
    
    for(int i = 0; i < numCourses; ++i) {
        if(status[i] == UNVISITED) {
            ans = ifCycle(graph, status, numCourses, i);
            if(ans == false)
                return false;
        }
        status[i] = VISITED;
    }
    return true;
}
