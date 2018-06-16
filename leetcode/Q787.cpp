/*
 There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

 Now given all the cities and fights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
 */
typedef pair<int, int> pii;

// Without dp
void getPrice(const vector<vector<pii>> &graph, const int current, const int &d, const int &k, int kTillNow, int &ans, int sumTillNow) {

    if(kTillNow > k || sumTillNow > ans)
        return;

    if(current == d) {
        if(sumTillNow < ans)
            ans = sumTillNow;
        return;
    }

    for(auto v : graph[current])
        getPrice(graph, v.first, d, k, kTillNow+1, ans, sumTillNow + v.second);
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

    if(n < 2)   return 0;

    vector<vector<pii>> graph(n);
    for(auto v : flights)
        graph[v[0]].push_back({v[1],v[2]});

    int ans = INT_MAX;
    getPrice(graph, src, dst, K, -1, ans, 0);
    return ans == INT_MAX ? -1 : ans;
}
