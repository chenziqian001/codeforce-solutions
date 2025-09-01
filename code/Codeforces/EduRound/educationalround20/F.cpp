#include<bits/stdc++.h>
using namespace std;

const int M=1000000007;

long long pw(long long a,long long n){
    long long res=1;
    a%=M;
    while(n){
        if(n&1) res=(res*a)%M;
        a=(a*a)%M;
        n>>=1;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int mx=*max_element(a.begin(),a.end());
    vector<long long> cnt(mx+1);
    for(int i=0;i<n;i++) cnt[a[i]]++;

    vector<long long> dp(mx+1,0);
    for(int i=mx;i>0;i--){
        long long c=0;
        dp[i]=0LL;
        for(int j=i;j<=mx;j+=i){
            c=(c+cnt[j])%M;
            dp[i]=(dp[i]-dp[j]+M)%M;
        }        
        long long val=(pw(2LL,c)-1+M)%M;
        dp[i]=(dp[i]+val)%M;
    }
    cout<<dp[1]<<'\n';
    system("pause");
    return 0;

}