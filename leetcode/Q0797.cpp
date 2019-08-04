/*
 Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
 
 The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
 */

typedef vector<int> vi;
typedef vector<vi> vvi;

void helper(const vvi &graph, const int &n, const int current, vi temp, vvi &ans, vector<bool> &visited) {
    
    temp.push_back(current);
    if(current == n) {
        ans.push_back(temp);
        return;
    }
    for(int node : graph[current])
        if(visited[node] == false) {
            visited[node] = true;
            helper(graph, n, node, temp, ans, visited);
            visited[node] = false;
        }
    temp.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    
    vector<vector<int>> ans;
    int n = graph.size();
    if(n == 0)
        return {};
    if(n == 1)
        return {};
    vector<bool> visited(n, false);
    visited[0] = true;
    --n;
    helper(graph, n, 0, {}, ans, visited);
    return ans;
}
