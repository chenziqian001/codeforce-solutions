#include <bits/stdc++.h>
 
#define int long long 
using namespace std;

struct dsu{
    vector<int> p, lvl;
    dsu(int n){
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        lvl.assign(n, 0);
    }
 
    int get(int i){
        if (p[i] == i) return i;
        return p[i] = get(p[i]);
    }
 
    bool unite(int a, int b){
        a = get(a);
        b = get(b);
        if(a == b) return false;
        if(lvl[a] < lvl[b]) swap(a, b);
        p[b] = a;
        if(lvl[a] == lvl[b]) lvl[a]++;
        return true;
    }
};
 
bool found;
vector<int> ans, path;
 
void dfs(int v, int p, vector<vector<int>> &g, int f){
    path.push_back(v);
    if(v == f){
        ans = path;
        found = true;
        return;
    }
    for(int u: g[v]){
        if(u != p) dfs(u, v, g, f);
        if (found) return;
    }
    path.pop_back();
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> sl(n);
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({w, {u, v}});
    }
    sort(edges.rbegin(), edges.rend());
    dsu g(n);
    pair<int, int> fin;
    int best = INT_MAX;
    for(auto e: edges){
        if(!g.unite(e.second.first, e.second.second)){
            fin = e.second;
            best = e.first;
        }
        else{
            sl[e.second.first].push_back(e.second.second);
            sl[e.second.second].push_back(e.second.first);
        }
    }
    found = false;
    path.resize(0);
    dfs(fin.first, -1, sl, fin.second);
    cout << best <<  " " << ans.size() << "\n";
    for(int e: ans) cout << e + 1 << " ";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}