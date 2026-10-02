#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
const int mod = 998244353;

void solve(){
    int n;cin>>n;
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        u--;v--; 
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(g[n-1].size()==1){
        cout<<"1\n";
        return;
    }

    vector<int> mx(n,-1);
    
    auto dfs1=[&](auto self,int c,int p)->void{
        for(int x:g[c]){
            if(x==p)continue;
            self(self,x,c);
            mx[c]=max({mx[c],x,mx[x]});
        }
    };
    dfs1(dfs1,n-1,-1);

    set<int,greater<int>> s;
    for(int i=0;i<n-1;i++)s.insert(i);

    vector<int> cur;
    auto dfs2=[&](auto self,int c,int p)->void{
        s.erase(c);
        cur.push_back(c);
        for(int x:g[c]){
            if(x==p)continue;
            self(self,x,c);
        }
    };
    
    vector<bool> ok(n,false);
    for(int x:g[n-1]){
        dfs2(dfs2,x,n-1);
        
        for(int u:cur){
            if(s.empty()||u>*s.begin())ok[u]=true;
        }
        for(int u:cur)s.insert(u);
        cur.clear();
    }
    ok[n-1]=true;

    int idx=-1;
    for(int i=0;i<n;i++){
        if(g[i].size()==1)idx=i;
    }

    vector<int> dp(n),pre(n);
    if(idx != -1) {
        dp[idx] = 1;
        pre[idx] = 1; 
    }
    for(int i=idx+1;i<n-1;i++){
        int l=mx[i]+1;
        if(l<i){
            dp[i]=pre[i-1];
            if(l) dp[i]=(dp[i]-pre[l-1]+mod)%mod;
        }
        pre[i]=(dp[i]+pre[i-1])%mod;
    }
    int res=0;
    for(int i=0;i<n;i++){
        if(ok[i]) res=(res+dp[i])%mod;
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
