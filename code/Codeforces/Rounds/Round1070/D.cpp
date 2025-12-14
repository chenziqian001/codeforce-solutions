#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

struct info{
    int u,v;
    int sum;
    bool operator<(const info &other) const{
        return sum<other.sum;
    }
};



void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<info> b(m);
    for(int i=0;i<m;i++){
        cin>>b[i].u>>b[i].v;
        b[i].u--,b[i].v--;
        b[i].sum=a[b[i].u]+a[b[i].v];
    }
    sort(b.begin(),b.end());
    map<int,int> dp[max(n,m)+10];

    int res=0;
    
    for(int i=0;i<m;i++){
        int val=dp[b[i].u][a[b[i].v]];
        res=(res+val+1)%mod;
        dp[b[i].v][a[b[i].v]+a[b[i].u]]=(dp[b[i].v][a[b[i].v]+a[b[i].u]]+val+1)%mod;
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