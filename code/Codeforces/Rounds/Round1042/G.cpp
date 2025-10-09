#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<int> dp(31);
vector<int> pre;
int dfs(int v,int k){
    if(k==0) return 1;
    int ans=v+1;
    v=min(v-1,30LL);
    k--;
    for(int i=0;i<=v;i++){
        if(k>=(1LL<<i)){
            ans=ans*dp[i]%mod;
            k-=(1LL<<i);
        }
        else{
            ans=ans*dfs(i,k)%mod;
            break;
        }
    }
    return ans;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        x--;
        a[i]=x;
    }
    sort(a.begin(),a.end());
    int res=1;
    for(int v:a){
        if(v<=30 && k>=(1LL<<v)){
            k-=(1LL<<v);
            res=res*dp[v]%mod;
        }
        else{
            res=res*dfs(v,k)%mod;
            break;
        }
    }

    cout<<res<<'\n';
}


signed main(){
    dp[0]=1;
    pre.resize(32,1);
    for(int i=1;i<31;i++){
        dp[i]=(i+1)*pre[i-1]%mod;
        pre[i]=pre[i-1]*dp[i]%mod;
    }
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}






