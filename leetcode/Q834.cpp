/*
 An undirected, connected tree with N nodes labelled 0...N-1 and N-1 edges are given.
 
 The ith edge connects nodes edges[i][0] and edges[i][1] together.
 
 Return a list ans, where ans[i] is the sum of the distances between node i and all other nodes.
 */

typedef vector<int> vi;
typedef vector<vi> vvi;
vi ans;
vi count1;
vvi graph;
int n;

int root(int current, int parent) {
    
    for(int node : graph[current]) {
        if(node == parent)
            continue;
        count1[current] += root(node, current);
        // + count1[node] to add one to path to each node in subtree rooted at child node
        ans[current] += count1[node] + ans[node];
    }
    ++count1[current];
    return count1[current];
}

void other(int current, int parent) {
    // - count1[current] to subtract one from all nodes present at current's subtree
    // + (n - count1[current]) add one to all the nodes present at parent's other children's subtrees
    ans[current] = ans[parent] - count1[current] + n - count1[current];
    for(auto node : graph[current]) {
        if(node == parent)
            continue;
        other(node, current);
    }
}

vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    
    count1.resize(N);
    ans.resize(N);
    n = N;
    
    graph.resize(N);
    for(auto v : edges) {
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }
    root(0, NULL);
    for(int node : graph[0])
        other(node, 0);
    
    return ans;
}
