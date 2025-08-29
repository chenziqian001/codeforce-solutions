#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;
void solve(){
    int n;
    cin>>n;
    vector<long long> dp(n);
    vector<long long> tot(n);
    vector<int> p(n);
    vector<int> d(n);
    vector<vector<int>> hei(n);
    for(int i=1;i<n;i++){
        cin>>p[i];
        p[i]--;
        d[i]=d[p[i]]+1;
        hei[d[i]].push_back(i);
    }
    dp[0]=tot[0]=1LL;
    for(int i=1;i<n;i++){
        for(int num:hei[i]){
            if(d[num]==1) dp[num]=tot[d[num]-1];
            else dp[num]=(tot[d[num]-1]-dp[p[num]]+MOD)%MOD;
            tot[d[num]]=(tot[d[num]]+dp[num])%MOD;
        }
    }
    long long res=0;
    for(int i=0;i<n;i++){
        res=(res+dp[i])%MOD;
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