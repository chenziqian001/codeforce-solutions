#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int inf=1e18;

int q[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> dp(n+1,inf);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int sum=0;
        int mx=0;
        for(int j=i;j>=1;j--){
            sum+=a[j];
            mx=max(mx,a[j]);
            if(sum<=m){
                dp[i]=min(dp[i],dp[j-1]+mx);
            }
            else break;
        }
    }

    cout<<dp[n]<<'\n';
    //system("pause");
}

