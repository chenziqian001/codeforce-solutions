#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
const int mod=1e9+7;
int n;
long long qpow(long long a,long long n){
    long long res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}
void solve(){
    cin>>n;
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> len;
    int lca=-1;
    function<void(int,int,int)> dfs=[&](int u,int fa,int l){
        bool isl=true;
        if(t[u].size()>2) lca=l;
        for(int v:t[u]){
            if(v==fa) continue;
            dfs(v,u,l+1);
            isl=false;
        }
        if(isl) len.push_back(l);
    };
    t[0].push_back(n);
    dfs(0,n,1);
    if(len.size()>2){
        cout<<0<<'\n';
    }
    else if(len.size()==1){
        cout<<qpow(2,n)<<'\n';
    }
    else{
        int diff=abs(len[0]-len[1]);
        int x=lca+diff;
        if(diff){
            cout<<(qpow(2,x)+qpow(2,x-1))%mod<<'\n';
        }
        else{
            cout<<2*qpow(2,x)%mod<<'\n';
        }
        
    }


}    
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}