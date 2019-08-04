/*
 In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.
 
 The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.
 
 The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.
 
 Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.
 */

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;


bool dfsWithout(const vvi &graph, pii edge, int &count, int current, vector<bool> &visited) {
    
    bool ans = false;
    visited[current] = true;
    --count;
    for(auto v : graph[current]) {
        if(visited[v] == false && (current != edge.first || v != edge.second)) {
            ans |= dfsWithout(graph, edge, count, v, visited);
        }
    }
    return count == 0 ? true : ans;
}

bool DFS(const vvi &graph, int current, vector<bool> &visited, vi &temp) {
    
    if(visited[current]) {
        temp.push_back(current);
        return true;
    }
    
    visited[current] = true;
    for(auto node : graph[current])
        if(DFS(graph, node, visited, temp)) {
            temp.push_back(current);
            return true;
        }
    return false;
}


vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    
    int n = edges.size(), root = 0, index = 1;
    map<pair<int,int>, int> mapp;   // Stores order of edges
    vvi graph(n + 1);
    vi incoming(n+1);   // parent of each vertex
    vector<bool> visited(n+1);
    vector<pii> toBeRemoved;
    
    for(auto v : edges) {
        mapp[{v[0], v[1]}] = index++;
        graph[v[0]].push_back(v[1]);
        if(incoming[v[1]]) {
            toBeRemoved.push_back({incoming[v[1]], v[1]});
            toBeRemoved.push_back({v[0], v[1]});
        }
        // Vertex with 2 incoming edges
        else
            incoming[v[1]] = v[0];
    }
    
    // Find root
    for(int i = 1; i <= n; ++i) {
        if(incoming[i] == 0) {
            root = i;
            break;
        }
    }
    
    if(toBeRemoved.size()) {
        // If all vertices can be traversed without 2nd incoming edge
        if(dfsWithout(graph, toBeRemoved[1], n, root, visited))
            return {toBeRemoved[1].first, toBeRemoved[1].second};
        else
            return {toBeRemoved[0].first, toBeRemoved[0].second};
    }
    
    for(int i = 0; i <= n; ++i)
        visited[i] = false;
    incoming = {};
    bool found = false;
    index = 1;
    
    // Root is present, traverse the graph and find redundant edge
    if(root)
        DFS(graph, root, visited, incoming);
    else {
        // Travel until the cycle is found
        while(found == false){
            while(index <= n && visited[index] == true)
                ++index;
            found = DFS(graph, index, visited, incoming);
        }
    }
    
    n = incoming.size();
    root = incoming[n-1];
    index = 0;
    int newIndex, i = 0, finalIndex;
    
    while(i <= n) {
        newIndex = mapp[{incoming[i + 1], incoming[i]}];
        if(newIndex > index) {
            index = newIndex;
            finalIndex = i;
        }
        ++i;
        if(incoming[i] == root)
            break;
    }
    return {incoming[finalIndex + 1], incoming[finalIndex]};
}
