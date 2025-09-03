#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<long long> a(n);
    
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int mx=a[n-1];
    vector<long long> cnt(mx+1);
    for(int i=0;i<n;i++) cnt[a[i]]++;
    vector<long long> bigger(mx+1);
    for(int i=n-2;i>=0;i--){
        if(a[i]==a[i+1]) bigger[a[i]]=bigger[a[i+1]];
        else bigger[a[i]]=n-i-1;
    } 
    vector<long long> dp(mx+1);
    for(int i=1;i<=mx;i++){
        long long c=0;
        for(int j=i;j<=mx;j+=i){
            int big=bigger[j];
            dp[i]+=c*cnt[j]*(cnt[j]-1)/2+c*cnt[j]*big+cnt[j]*(cnt[j]-1)/2*big+cnt[j]*(cnt[j]-1)*(cnt[j]-2)/6;
            c+=cnt[j];
        }
    }
    long long res=0;
    for(int i=mx;i>0;i--){
        for(int j=i*2;j<=mx;j+=i){
            dp[i]-=dp[j];
        }
        res+=dp[i]*i;
    }
    cout<<res<<'\n';
    


}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}