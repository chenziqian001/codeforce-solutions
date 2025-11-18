#include<bits/stdc++.h>
using namespace std;
#define int long long
const  int N=1e5+10;

int q[N];
int b[N];


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    q[0]=0;
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    
    vector<int> dp(n+1);
    int res=0;
    int l=0,r=0;
 
    for(int i=1;i<=n;i++){
        b[i]=dp[i-1]-pre[i];
        while(l<=r && q[l]<i-k) l++;
        while(l<=r && b[i]>b[q[r]]) r--;
        q[++r]=i;
        dp[i]=b[q[l]]+pre[i];
        res=max(res,dp[i]);
    }
    cout<<res<<'\n';
    //system("pause");
}