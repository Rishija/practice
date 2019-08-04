/*
 Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
 */

void helper(const vector<vector<int>> &graph, vector<bool> &V, int node) {
    for(int neighbour : graph[node]) {
        if(V[neighbour] == false) {
            V[neighbour] = true;
            helper(graph, V, neighbour);
        }
    }
}

int countComponents(int n, vector<pair<int, int>>& edges) {
    int cnt = 0;
    vector<bool> V(n);
    vector<vector<int>> graph(n);
    for(auto p : edges) {
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
    }
    
    for(int i = 0; i < n; ++i) {
        if(V[i] == false) {
            helper(graph, V, i);
            ++cnt;
        }
    }
    return cnt;
}
