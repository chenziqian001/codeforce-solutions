#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=2e5+10;
int n,m;
vector<long long> fac(N);
void init(){
    fac[0]=1;
    for(int i=1;i<=N;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
}
void solve(){
    cin>>n>>m;
    vector<vector<int>> t(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    if(m>=n){
        cout<<0<<'\n';
        return;
    }
    long long res=2;
    int tll=0;
    for(int u=0;u<n;u++){
        if(t[u].size()>1){
            int x=0;
            for(int v:t[u]) x+=(t[v].size()==1);
            if(x>=(t[u].size()-2)) res=(res*fac[x])%mod;
            else res=0;
        }
        else tll++;
    }
    int c;
    if(tll<n-1) c=2;
    else c=1;
    cout<<res*c%mod<<'\n';
   
}
signed main(){
    init();
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}
