#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int main(){
    int n;
    cin>>n;
    vector<int> val(n);
    for(int i=0;i<n;i++) cin>>val[i];
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    int mx=*max_element(val.begin(),val.end());
    vector<vector<int>> fac(mx+1);
    for(int i=0;i<n;i++){
        fac[val[i]].push_back(i);
    }
    vector<long long> gcd_val(n);
    auto dfs=[&](auto&& dfs,int u,int fa,int value)->int{
        gcd_val[u]=value;
        long long sz=1;
        for(int v:t[u]){
            if(v==fa || val[v]%value!=0) continue;
            sz+=dfs(dfs,v,u,value);
        }
        return sz;
    };
    vector<long long> dp(mx+1);
    for(int i=1;i<=mx;i++){
        for(int j=i;j<=mx;j+=i){
            for(int node:fac[j]){
                if(gcd_val[node]==i) continue;
                long long sz=dfs(dfs,node,-1,i);
                dp[i]+=sz*(sz+1)/2;
            }
        }
    }
    for(int i=mx;i>0;i--){
        for(int j=i*2;j<=mx;j+=i){
            dp[i]-=dp[j];
        }
    }
    for(int i=1;i<=mx;i++){
        if(dp[i]!=0){
            cout<<i<<" "<<dp[i]<<'\n';
        }
    }
    system("pause");
    return 0;
}