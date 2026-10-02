#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
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
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<int> fw(n+1);
    auto add=[&](int pos,int val){
        for(int i=pos;i<=n;i+=i&-i) fw[i]+=val;
    };
    auto get=[&](int pos){
        int res=0;
        for(int i=pos;i>0;i-=i&-i) res+=fw[i];
        return res;
    };
    vector<pair<int,int>> g;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g.emplace_back(a[i]*b[j],i+1);
        }
    }
    sort(g.rbegin(),g.rend());
    int ia=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) ia++;
        }
    }
    int base=0;
    for(int i=0;i<n*n;){
        int ed=i;
        while(ed<n*n && g[ed].first==g[i].first) ed++;
        for(int j=i;j<ed;j++) base=(base+get(g[j].second-1))%mod;
        for(int j=i;j<ed;j++) add(g[j].second,1);
        i=ed;
    }
    int res=(base-n*ia%mod+mod)%mod;
    res=res*inv(n)%mod;
    res=res*inv(n-1)%mod;
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