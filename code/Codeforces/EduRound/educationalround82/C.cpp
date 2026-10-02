#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    string s;
    cin>>s;
    int n=s.size();
    
    vector<set<int>> g(26);
    for(int i=1;i<n;i++){
        int u=s[i]-'a';
        int v=s[i-1]-'a';
        g[u].insert(v);
        g[v].insert(u);
    }
    for(int i=0;i<26;i++){
        if(g[i].size()>2){
            cout<<"NO"<<'\n';
            return;
        }
    }
    vector<int> vis(26,0);
    bool ok=true;
    function<void(int,int)> dfs=[&](int node,int fa){
        if(vis[node]==2) return;
        else if(vis[node]==1){
            ok=false;
            return;
        }
        vis[node]=1;
        for(int next:g[node]){
            if(next==fa) continue;
            dfs(next,node);
        }
        vis[node]=2;
    };
    for(int i=0;i<26;i++){
        if(vis[i]==0){
            dfs(i,-1);
        }
    }
    if(!ok){
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
    string res="";
    vis.assign(26,0);
    for(int i=0;i<26;i++){
        if(g[i].size()==1 && !vis[i]){
            int pre=-1;
            int tmp=i;
            while(1){
                vis[tmp]=1;
                res+=('a'+tmp);
                int nx=-1;
                for(int x:g[tmp]){
                    if(x!=pre){
                        nx=x;
                    }
                }
                if(nx==-1) break;
                pre=tmp;
                tmp=nx;
            }
        }
    }
    for(int i=0;i<26;i++){
        if(!vis[i]) res+=('a'+i);
    }
    cout<<res<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}