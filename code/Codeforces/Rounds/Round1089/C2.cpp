#include<bits/stdc++.h>
using namespace std;
#define int long long
int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}
int P[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n),g(n),l(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n-1;i++) g[i]=__gcd(a[i],a[i+1]);

    l[0]=g[0];
    l[n-1]=g[n-2];
    for(int i=1;i<n-1;i++){
        l[i]=lcm(g[i-1],g[i]);
    }


    auto get=[&](int i){
        vector<pair<int,int>> res={{a[i],0}};
        if(l[i]!=a[i] && l[i]<=b[i]) res.push_back({l[i],1});
        else if(a[i]==l[i]){
            int cnt=0;
            for(int p:P){
                if(p*l[i]<=b[i] && cnt++<=22){
                    res.push_back({p*l[i],1});
                }
            }
        }
        return res;
    };

    vector<pair<int,int>> dp=get(0);
    for(int i=1;i<n;i++){
        vector<pair<int,int>> ndp;
        for(auto [cm,cv]:get(i)){
            int mx=-1;
            for(auto [pm,pv]:dp){
                if(__gcd(pm,cm)==g[i-1]){
                    mx=max(mx,pv+cv);
                }
            }
            if(mx!=-1) ndp.push_back({cm,mx});
        }
        dp=move(ndp);
    }

    int res=0;
    for(auto [m,v]:dp){
        res=max(res,v);
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