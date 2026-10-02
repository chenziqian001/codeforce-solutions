#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> gp(n+1);
    vector<vector<int>> t(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    int id=1;
    vector<int> in(n+1);
    vector<int> out(n+1);
    function<void(int,int)> dfs=[&](int node,int fa){
        in[node]=id++;
        gp[node]=gp[fa]^1;
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
        }
        out[node]=id-1;
    };
    dfs(1,0);
    vector<int> fw0(id+1);
    vector<int> fw1(id+1);
    auto add=[&](vector<int> &fw,int pos,int val){
        for(int i=pos;i<fw.size();i+=i&-i) fw[i]+=val;
    };
    auto get=[&](vector<int> &fw,int pos){
        int res=0;
        for(int i=pos;i>0;i-=i&-i) res+=fw[i];
        return res;
    };

    for(int i=0;i<m;i++){
        int tp;cin>>tp;
        if(tp==1){
            int x,val;
            cin>>x>>val;
            if(gp[x]==0){
                add(fw0,in[x],val);
                add(fw0,out[x]+1,-val);
                add(fw1,in[x],-val);
                add(fw1,out[x]+1,val);
            }
            else{
                add(fw1,in[x],val);
                add(fw1,out[x]+1,-val);
                add(fw0,in[x],-val);
                add(fw0,out[x]+1,val);
            }
        }
        else{
            int x;cin>>x;
            int ans;
            if(gp[x]==0){
                ans = a[x] + get(fw0, in[x]); 
            } 
            else{
                ans=a[x]+get(fw1,in[x]);
            }
            cout<<ans<<'\n';
        }

    }


}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //system("pause");
    return 0;
}
