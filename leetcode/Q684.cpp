/*
 In this problem, a tree is an undirected graph that is connected and has no cycles.

 The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

 The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

 Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.
 */
typedef vector<int> vi;
typedef vector<vi> vvi;
enum status {UNVISITED, VISITED, INPROCESS};

/**
 * Return once found

bool helper(const vvi & graph, int current, int parent, vi &status, vi &ans, bool &done) {

    status[current] = INPROCESS;
    bool found;
    for(auto node : graph[current]) {
        if(done)
            return false;
        if(status[node] == INPROCESS && node != parent) {
            ans.push_back(node);
            ans.push_back(current);
            return true;
        }
        if(status[node] == UNVISITED) {
            found = helper(graph, node, current, status, ans, done);
            if(found) {
                ans.push_back(current);
                if(current == *ans.begin()) {
                    done = true;
                    return false;
                }
                return true;
            }
        }
    }
    status[current] = VISITED;
    return false;
}
*/

bool helper(const vvi & graph, int current, int parent, vi &status, vi &ans) {

    status[current] = INPROCESS;
    bool found;
    for(auto node : graph[current]) {
        if(status[node] == INPROCESS && node != parent) {
            ans.push_back(node);
            ans.push_back(current);
            return true;
        }
        if(status[node] == UNVISITED) {
            found = helper(graph, node, current, status, ans);
            if(found) {
                ans.push_back(current);
                if(current == *ans.begin())
                    return false;
                return true;
            }
        }
    }
    status[current] = VISITED;
    return false;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {

    int n = edges.size();
    if(n < 2)
        return {};

    vvi graph(n);
    int index = 1;
    map<pair<int,int>, int> mapp;
    for(auto e : edges) {
        --e[0];
        --e[1];
        mapp[{e[0], e[1]}] = index++;
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    vi status(n), ans, pair;
    helper(graph, 0, -1, status, ans);

    index = 0;
    n = ans.size();
    int newIndex;
    for(int i = 0; i < n - 1; ++i) {
        newIndex = mapp[{min(ans[i], ans[i+1]), max(ans[i], ans[i+1])}];
        if(newIndex > index) {
            index = newIndex;
            pair = {ans[i], ans[i+1]};
        }
    }
    return {min(pair[0], pair[1]) + 1, max(pair[0],pair[1]) + 1};
}

void print(vvi vec) {

    vi ans = findRedundantConnection(vec);
    for(int x : ans)
        cout << x << " ";
    cout << endl;
}

int main() {

    vvi vec;

    vec = {{21,22},{4,7},{12,13},{13,25},{12,15},{17,23},{15,16},{8,21},{23,24},{3,9},{19,21},{13,21},{4,10},{5,6},{1,20},{10,16},{1,4},{10,14},{5,20},{1,2},{3,24},{2,11},{11,24},{24,25},{17,18}};
    print(vec); // 24 25

    vec = {{20,24},{3,17},{17,20},{8,15},{14,17},{6,17},{15,23},{6,8},{15,19},{16,22},{7,9},{8,22},{2,4},{4,11},{22,25},{6,24},{13,19},{15,18},{1,9},{4,9},{4,19},{5,10},{4,21},{4,12},{5,6}};
    print(vec); // 6 24

    vec = {{2,7},{7,8},{3,6},{2,5},{6,8},{4,8},{2,8},{1,8},{7,10},{3,9}};
    print(vec); // 2 8

    vec = {{1,2}, {1,3}, {2,3}};
    print(vec); // 2 3

    vec = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    print(vec); // 1 4

    return 0;
}
