#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9+10;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> dp(7);
    

    for(int x=1;x<=6;x++){
        dp[x]=(x==a[0])?0:1;
    }

    for(int i=1;i<n;i++){
        vector<int> ndp(7,inf);
        for(int x=1;x<=6;x++){
            for(int y=1;y<=6;y++){
                if(y==x || y==7-x) continue;
                ndp[x]=min(ndp[x],dp[y]);
                
            }
            ndp[x]+=(x==a[i]?0:1);
        }
        dp=ndp;
    }

    int res=inf;
    for(int x=1;x<=6;x++){
        res=min(res,dp[x]);
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
