#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int qp(int a,int b){
    int r=1;
    while(b){
        if(b&1)r=r*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return r;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int m=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m+=a[i];
    }
    vector<int> f(m+1,1),inv(m+1,1);
    for(int i=1;i<=m;i++)f[i]=f[i-1]*i%MOD;
    inv[m]=qp(f[m],MOD-2);
    for(int i=m-1;i>=1;i--)inv[i]=inv[i+1]*(i+1)%MOD;
    auto C=[&](int n,int k)->int{
        if(k<0||k>n)return 0;
        return f[n]*inv[k]%MOD*inv[n-k]%MOD;
    };
    vector<int> dp(m+1,0);
    dp[0]=1;
    int A=0;
    for(int i=0;i<n;i++){
        vector<int> ndp(m+1,0);
        for(int s=0;s<=A;s++){
            if(!dp[s])continue;
            for(int c=0;c<=a[i];c++){
                if(2*s+c<=A){
                    ndp[s+c]=(ndp[s+c]+dp[s])%MOD;
                }
            }
        }
        dp=ndp;
        A+=a[i];
    }
    int ans=0;
    for(int k=0;k<=m/2;k++){
        if(!dp[k])continue;
        int ways=(C(m,k)-C(m,k-1)+MOD)%MOD;
        ans=(ans+dp[k]*ways)%MOD;
    }
    cout<<ans<<"\n";
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