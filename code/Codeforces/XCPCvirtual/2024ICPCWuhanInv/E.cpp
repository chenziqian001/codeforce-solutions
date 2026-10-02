#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;

 
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    int rt,t0;
    cin>>rt>>t0;

    vector<int> dep(n+1);
    dep[0]=-1;
    vector<vector<int>> up(n+1,vector<int>(20));
    function<void(int,int)> dfs=[&](int node ,int fa){
        up[node][0]=fa;
        dep[node]=dep[fa]+1;
        for(int i=1;i<20;i++){
            up[node][i]=up[up[node][i-1]][i-1];
        }
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
        }
    };
    dfs(rt,0);

    auto get_lca=[&](int u,int v){
        if(dep[u]<dep[v]) swap(u,v);
        int diff=dep[u]-dep[v];
        for(int i=19;i>=0;i--){
            if(diff>>i&1) u=up[u][i];
        }
        if(u==v) return u;
        for(int i=19;i>=0;i--){
            if(up[u][i]!=up[v][i]){
                u=up[u][i];
                v=up[v][i];
            }
        }
        return up[u][0];
    };
    auto get_dis=[&](int u,int v){
        return dep[u]+dep[v]-2*dep[get_lca(u,v)];
    };
    
    vector<int> len(2*n+1);
    vector<vector<int>> nodes(n+1);
    for(int i=1;i<=n;i++){
        nodes[dep[i]].push_back(i);
    }
    
    int l=rt,r=rt,D=0;
    for(int i=0;i<=n;i++){
        for(int u:nodes[i]){
            int d1=get_dis(l,u);
            int d2=get_dis(r,u);
            if(d1>D && d1>=d2){
                D=d1;
                r=u;
            }
            else if(d2>D && d2>=d1){
                D=d2;
                l=u;
            }
        }
        len[i]=(D+1)/2;
    }
    for(int i=n+1;i<=2*n;i++) len[i]=len[n];
    for(int k=1;k<=n;k++){
        int L=t0,R=2*n,res=R;
        while(L<=R){
            int mid = (L+R)/2;
            if(k*(mid-t0)>=len[mid]){
                res=mid;
                R=mid-1;
            }
            else L=mid+1;
        }
        cout<<res<<" ";
    }
    cout<<'\n';




    
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
 
 