#include<bits/stdc++.h>
using namespace std;
#define int long long

struct info{
    int x,w,c;
    bool operator<(const info&o) const{
        if(x!=o.x) return x<o.x;
        if(c!=o.c) return c>o.c;
        return w<o.w;
    }
};


void solve(){
    int n,k;
    cin>>n>>k;


    vector<info> a(n);
    for(int i=0;i<n;i++) cin>>a[i].x>>a[i].w>>a[i].c;
    sort(a.begin(),a.end());
    vector<int> dp(n);
    int res=0;
    for(int i=0;i<n;i++){
        dp[i]=-200*a[i].w;
        for(int j=0;j<i;j++){
            if(a[j].x<a[i].x){
                dp[i]=max(dp[i],dp[j]+k*(a[i].c+a[j].c)*(a[i].x-a[j].x)-200*a[i].w);
            }
        }
        res=max(res,dp[i]);
    }

   cout<<fixed<<setprecision(6)<<(double)res/200.0<<'\n';

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