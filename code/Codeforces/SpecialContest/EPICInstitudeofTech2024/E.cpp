#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<vector<int>> t(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int f;
        cin>>f;
        f--;
        t[f].push_back(i);
    }

    vector<vector<int>> dp(n,vector<int>(n));
    vector<int> dep(n);
    int res=0;

    function<void(int)> dfs=[&](int node){
        if(t[node].empty()){
            dp[node][0]+=inf;
            return;
        }
        int sum=0;
        for(int next:t[node]){
            dfs(next);
            sum+=a[next];
            dep[node]=max(dep[node],dep[next]+1);
            for(int i=0;i<=dep[next];i++){
                dp[node][i+1]+=dp[next][i];
            }
        }

        if(a[node]<=sum){
            dp[node][0]+=sum-a[node];
        }
        else{
            int tt=a[node]-sum;
            for(int i=0;i<=dep[node];i++){
                int cost=min(tt,dp[node][i]);
                res+=i*cost;
                tt-=cost;
                dp[node][i]-=cost;
            }
        }

    };
    dfs(0);
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