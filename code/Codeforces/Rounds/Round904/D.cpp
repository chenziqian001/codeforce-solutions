#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> cnt(n+1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    vector<int> s(n+1);
    vector<int> dp(n+1);

    for(int i=n;i>=1;i--){
        s[i]=cnt[i];
        for(int j=2*i;j<=n;j+=i){
            s[i]+=cnt[j];
        }
    }

    for(int i=n;i>=1;i--){
        dp[i]=s[i]*(s[i]-1)/2;
        for(int j=2*i;j<=n;j+=i){
            dp[i]-=dp[j];
        }
    }

    vector<bool> ok(n+1,true);
    for(int i=1;i<=n;i++){
        if(cnt[i]){
            for(int j=i;j<=n;j+=i){
                ok[j]=false;
            }
        }
    }


    int res=0;
    for(int i=1;i<=n;i++){
        if(ok[i]){
            res+=dp[i];
        }
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