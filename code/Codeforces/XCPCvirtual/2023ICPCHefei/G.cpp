#include <bits/stdc++.h>
using namespace std;
#define int long long 


void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    vector<int> zeros(n+1),nxt(n+1,n);
    for(int i=0;i<n;i++)zeros[i+1]=zeros[i]+(s[i]=='0');
    for(int i=n-1;i>=0;i--){
        if(s[i]=='0')nxt[i]=i;
        else nxt[i]=nxt[i+1];
    }
    vector<array<int,6>> dp(n+2);
    auto check=[&](int x){
        for(int i=0;i<=n+1;i++){
            for(int j=1;j<=k;j++)dp[i][j]=1e9;
            dp[i][0]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                dp[i][j]=dp[i+1][j];
                if(i+x<=n){
                    int c=zeros[i+x]-zeros[i];
                    int ns=min(n+1,nxt[i+x]+1);
                    dp[i][j]=min(dp[i][j],c+dp[ns][j-1]);
                }
            }
        }
        return dp[0][k]<=m;
    };
    int l=1,r=n,ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<"\n";

    

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //system("pause");
    return 0;
}