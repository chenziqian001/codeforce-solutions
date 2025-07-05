#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
const int M=998244353;


int fast_pow(int a,int n){
    int res=1;
    while(n){
        if(n&1){
            res=(res*a)%M;
        }
        a=(a*a)%M;
        n>>=1;
    }
    return res;
}

int fact(int x){
    int res=1;
    for(int i=x;i>=1;i--){
        res=(res*i)%M;
    }
    return res;
}


void solve(){
    int c[26];
    long long sum=0;
    for(int i=0;i<26;i++) cin>>c[i];
    for(int i=0;i<26;i++) sum+=c[i];
    vector<int> dp(sum+1);
    dp[0]=1;
    for(int i=0;i<26;i++){
        if(c[i]==0) continue;
        for(int j=sum;j>=0;j--){
            if(dp[j]&&j+c[i]<=sum){
                dp[j+c[i]]=(dp[j+c[i]]+dp[j])%M;
            }
        }
    }
    int odd=(sum+1)/2;
    int even=sum/2;

    int ans=dp[odd]*fact(odd)%M*fact(even)%M;
    for(int i=0;i<26;i++){
        if(c[i]==0) continue;
        ans=(ans*fast_pow(fact(c[i]),M-2))%M;
    }
    cout<<ans<<'\n';

    return;
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}