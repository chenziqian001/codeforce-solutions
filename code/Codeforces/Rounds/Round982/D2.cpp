#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
const int mod=1e9+7;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> b(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    
    int mx=*max_element(a.begin()+1,a.end());
    if(mx>b[1]){
        cout<<-1<<'\n';
        return;
    }
    vector<pair<int,int>> dp(n+1,{inf,0});
    dp[0]={0,1};
    
    for(int k=1;k<=m;k++){
        int sum=0;
        for(int i=1,j=0,l=0;i<=n;i++){

            while(pre[i]-pre[j]>b[k]){
                sum=(sum-dp[j].second+mod)%mod;
                j++;
            }
            
            if(l<j){
                l=j;
                sum=0;
            }

            while(l<i && dp[l].first==dp[j].first){
                sum=(sum+dp[l].second)%mod;
                l++;
            }
            
            if(j<i){
                int v=dp[j].first+m-k;
                if(v<dp[i].first){
                    dp[i]={v,sum};
                }
                else if(v==dp[i].first){
                    dp[i].second=(dp[i].second+sum)%mod;
                }
            }
        }
    }


    if(dp[n].first==inf){
        cout<<-1<<'\n';
    }
    else{
        cout<<dp[n].first<<" "<<dp[n].second<<'\n';
    }

}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
