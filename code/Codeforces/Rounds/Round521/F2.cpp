#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
int q[5010];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    
    vector<int> dp(n+1,-inf);
    vector<int> ndp(n+1,-inf);
    dp[0]=0;
    
    for(int j=1;j<=x;j++){
        int l=1,r=0;
        ndp.assign(n+1,-inf);
        for(int i=1;i<=n;i++){
            int p=i-1;
            if (dp[p] != -inf) {
                while(l <= r && dp[q[r]] <= dp[p]) r--;
                q[++r] = p;
            }
            while(l<=r && q[l]<i-k) l++;
            if(l<=r) ndp[i]=dp[q[l]]+a[i];
        }
        swap(dp,ndp);
    }


    int res=-inf;
    for(int i=n-k+1;i<=n;i++){
        res=max(res,dp[i]);
    }
    if(res==-inf){
        cout<<-1<<'\n';
    }
    else cout<<res<<'\n';
    
    //system("pause");
    return 0;
}