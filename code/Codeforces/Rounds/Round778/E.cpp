#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    
    vector<int> cnt(32500005);
    int B=320;
    int res=0;
    for(int d=-B;d<=B;d++){
        int off=d>0?n*d:0;
        for(int i=1;i<=n;i++){
            int a0=a[i]-i*d+off;
            cnt[a0]++;
            res=max(res,cnt[a0]);
        }
        for(int i=1;i<=n;i++){
            int a0=a[i]-i*d+off;
            cnt[a0]--;
        }
    }
    vector<vector<pair<int,int>>> dp(n+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=B && i-j>=1;j++){
            int diff=a[i]-a[i-j];
            if(diff%j!=0) continue;
            int d=diff/j;
            if(abs(d)<=B) continue;


            int mx=2;
            for(auto &p:dp[i-j]){
                if(p.first==d){
                    mx=p.second+1;
                    break;
                }
            }
            res=max(res,mx);
            bool ok=false;
            for(auto &p:dp[i]){
                if(p.first==d){
                    p.second=max(p.second,mx);
                    res=max(res,p.second);
                    ok=true;
                    break;
                }
            }
            if(!ok){
                dp[i].emplace_back(d,mx);
            }
        }
    }
    cout<<n-res<<'\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
    //system("pause");
    return 0;
}


