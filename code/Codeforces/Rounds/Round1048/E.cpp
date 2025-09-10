#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> fa(n+1);
    vector<int> dep(n+1);
    vector<int> cnt(n+1);
    vector<int> is_lef(1+n,1);
    dep[1]=1;
    cnt[1]=1;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        fa[i]=x;
        dep[i]=dep[x]+1;
        cnt[dep[i]]++;
        is_lef[x]=0;
    }
    int mxdep=1e9;
    int sum=0;
    for(int i=1;i<=n;i++){
        if(is_lef[i]) mxdep=min(mxdep,dep[i]);
    }
    bitset<200005> dp;
    dp[0]=1;
    for(int i=1;i<=mxdep;i++){
        sum+=cnt[i];
        dp|=(dp<<cnt[i]);
    }
    if(sum<=k || sum<=n-k){
        cout<<mxdep<<'\n';
        return;
    }
    for(int i=0;i<=sum;i++){
        if(dp[i]){
            if(i<=k && sum-i<=n-k){
                cout<<mxdep<<'\n';
                return;
            }
        }
    }
    cout<<mxdep-1<<'\n';

}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;

}