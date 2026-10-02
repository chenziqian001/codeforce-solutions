#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> c(n);
    for(int i=0;i<n;i++) cin>>c[i].first;
    for(int i=0;i<n;i++) cin>>c[i].second;
    int res=0;
    sort(c.begin(),c.end());
    vector<int> cnt(n+1);

    for(int d=1;d*d<=2*n;d++){
        cnt.assign(n+1,0);
        for(auto [a,b]:c){
            int v=a*d-b;
            if(v>=1 && v<=n) res+=cnt[v];
            if(a==d) cnt[b]++;
        }
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