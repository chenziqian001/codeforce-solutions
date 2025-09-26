#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    vector<int> dp(sum+1);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=sum-a[i];j>=0;j--){
            dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
        }
    }
    int res=0;
    for(int s=0;s<=sum;s++){
        res=(res+dp[s]*((s+1)/2)%mod)%mod;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            res=(res+(a[i]-(a[i]+j+1)/2)*dp[j])%mod;
        }
    }
    cout<<res<<'\n';
    system("pause");
    return 0;
}