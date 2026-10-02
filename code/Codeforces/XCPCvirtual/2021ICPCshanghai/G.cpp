#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;


int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int inv(int x){
    return qp(x,mod-2);
}



void solve(){
    int n;
    cin>>n;
    
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }


    int res=1;


    vector<int> dp(n);

    function<void(int,int)> dfs=[&](int node,int fa){
        int cnt=0;

        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
            if(dp[next]==0) cnt++;
        }

        if(cnt%2==1){
            dp[node]=1;
            res=res*cnt%mod;
            cnt--;
        }
        int val=1;
        for(int i=1;i<=cnt-1;i+=2){
            val=val*i%mod;
        }
        if(val) res=res*val%mod;
    };

    dfs(0,-1);
    cout<<res<<'\n';
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