#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;
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

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n+1);
    int mx=0;
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        a[i]={l,r};
        mx=max(mx,r);
    }
    vector<int> nxt(mx+2);
    for(int i=0;i<=mx+1;i++) nxt[i]=i;
    function<int(int)> find=[&](int x){
        return ((x==nxt[x])?x:(nxt[x]=find(nxt[x])));
    };
    int res=0;
    for(int i=n;i>=1;i--){
        int w=(i==1)?qp(2,n-1):(qp(2,n-i+1)*qp(3,i-2)%mod);
        for(int j=find(a[i].first);j<=a[i].second;j=find(j)){
            res=(res+w)%mod;
            nxt[j]=j+1;
        }
    }
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