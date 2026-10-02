#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18;

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<vector<int>> dist(n + 1, vector<int>(51, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [d, u, c] = pq.top();
        pq.pop();

        if (d > dist[u][c]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (c == 0) {
                if (dist[v][w] > dist[u][0]) {
                    dist[v][w] = dist[u][0];
                    pq.push({dist[v][w], v, w});
                }
            } else {
                int cost = (c + w) * (c + w);
                if (dist[v][0] > dist[u][c] + cost) {
                    dist[v][0] = dist[u][c] + cost;
                    pq.push({dist[v][0], v, 0});
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dist[i][0] == INF) {
            cout << -1 << " ";
        } else {
            cout << dist[i][0] << " ";
        }
    }
    cout << "\n";
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;

}