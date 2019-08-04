/*
 In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.
 
 Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.
 
 Which nodes are eventually safe?  Return them as an array in sorted order.
 
 The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.
 */

typedef vector<int> vi;
typedef vector<vi> vvi;
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
    int n = graph.size();
    if(n == 0)  return {};
    if(n == 1)  return {0};
    vi ans;
    vvi incoming(n);
    vector<int> outgoing(n);
    vector<bool> choosen(n);
    bool found = true;
    
    for(int i = 0; i < n; ++i) {
        outgoing[i] = graph[i].size();
        for(int node : graph[i])
            incoming[node].push_back(i);
    }
    
    while(found) {
        found = false;
        for(int i = 0; i < n; ++i) {
            if(outgoing[i] == 0 && choosen[i] == false) {
                found = true;
                ans.push_back(i);
                choosen[i] = true;
                for(int node : incoming[i])
                    --outgoing[node];
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
