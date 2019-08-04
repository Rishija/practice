/*
 Given an undirected graph, return true if and only if it is bipartite.
 
 Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.
 
 The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.
 */

bool isBipartite(vector<vector<int>>& graph) {
    
    int n = graph.size();
    if(n < 3)   return true;
    
    vector<int> setNo(n,0);
    vector<bool> visited(n,0);
    queue<pair<int,int>> q;
    
    int current, index = 0;
    pair<int,int> i;
    
    while(index < n) {
        
        while(index < n && visited[index] == true)  ++index;
        if(index == n)  break;
        q.push({index,1});
        setNo[index] = 1;
        visited[index] = true;
        
        while(!q.empty()) {
            
            i = q.front();
            q.pop();
            
            for(auto node : graph[i.first]) {
                current = -1 * i.second;
                if(setNo[node] == 0)
                    setNo[node] = current;
                else if(setNo[node] != current)
                    return false;
                if(visited[node] == false) {
                    q.push({node, current});
                    visited[node] = true;
                }
            }
        }
    }
    return true;
}
