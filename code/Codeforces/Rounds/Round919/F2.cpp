#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Edge { int u, v, w_edge, winding; };

void solve(){
    int n,m,q;
    if(!(cin>>n>>m>>q)) return;
    vector<string> g(n);
    for(int i=0;i<n;i++) cin>>g[i];

    int rt=n,ct=-1;
    queue<int> qv;
    vector<int> d(n*m,-1);

    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            if(g[r][c]=='#'){
                if(r<rt){ rt=r; ct=c; }
            }else if(g[r][c]=='v'){
                d[r*m+c]=0;
                qv.push(r*m+c);
            }
        }
    }

    int dr[]={-1,1,0,0},dc[]={0,0,-1,1};
    while(!qv.empty()){
        int u=qv.front();
        qv.pop();
        int r=u/m,c=u%m;
        for(int i=0;i<4;i++){
            int nr=r+dr[i],nc=c+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){ 
                int nu=nr*m+nc;
                if(d[nu]==-1){
                    d[nu]=d[u]+1;
                    qv.push(nu);
                }
            }
        }
    }

    vector<Edge> edges;
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            if(g[r][c]=='#') continue;
            int u=r*m+c;
            if(c+1<m && g[r][c+1]!='#'){
                int v=r*m+c+1, w=0;
                if(r<rt && c==ct) w=1; 
                edges.push_back({u, v, min(d[u],d[v]), w});
            }
            if(r+1<n && g[r+1][c]!='#'){
                int v=(r+1)*m+c;
                edges.push_back({u, v, min(d[u],d[v]), 0}); 
            }
        }
    }
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        return a.w_edge > b.w_edge;
    });

    int cnt = n*m;
   
    vector<int> cycle_fa(n*m), cycle_val(n*m, 0);
    vector<int> krt_root(n*m), krt_val(n*m*4, 0), has_cycle(n*m*4, 0);
    vector<vector<int>> krt_adj(n*m*4);

    for(int i=0;i<n*m;i++){
        cycle_fa[i] = i;
        krt_root[i] = i;
        krt_val[i] = d[i];
    }

    auto find=[&](auto& self, int x)->int{
        if(cycle_fa[x]==x) return x;
        int p=cycle_fa[x];
        int root=self(self, p);
        cycle_val[x]+=cycle_val[p];
        return cycle_fa[x]=root;
    };

    for(auto& e : edges){
        int ru=find(find, e.u), rv=find(find, e.v);
        if(ru != rv){
            cycle_fa[ru] = rv;
            cycle_val[ru] = e.winding - cycle_val[e.u] + cycle_val[e.v];
            
            int p = cnt++;
            krt_val[p] = e.w_edge;
            has_cycle[p] = has_cycle[krt_root[ru]] | has_cycle[krt_root[rv]];
            krt_adj[p].push_back(krt_root[ru]);
            krt_adj[p].push_back(krt_root[rv]);
            krt_root[rv] = p; 
        } else {
            if(!has_cycle[krt_root[ru]]){
                if(e.winding - cycle_val[e.u] + cycle_val[e.v] != 0){
                    int p = cnt++;
                    krt_val[p] = e.w_edge;
                    has_cycle[p] = 1; 
                    krt_adj[p].push_back(krt_root[ru]);
                    krt_root[ru] = p;
                }
            }
        }
    }

    vector<int> final_ans(n*m, 0);
    auto dfs=[&](auto& self, int u, int cur_max)->void{
        if(has_cycle[u]) cur_max = max(cur_max, krt_val[u]);
        if(u < n*m) final_ans[u] = cur_max;
        for(int v : krt_adj[u]) self(self, v, cur_max);
    };

    int actual_root = -1;
    for(int i=0;i<n*m;i++){
        if(g[i/m][i%m]!='#'){
            actual_root = krt_root[find(find, i)];
            break; 
        }
    }
    dfs(dfs, actual_root, 0);

    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        cout<<final_ans[x*m+y]<<'\n';
    }
}

signed main(){
    //ios::sync_with_stdio(0);cin.tie(0);
    solve();
    system("pause");
    return 0;
}