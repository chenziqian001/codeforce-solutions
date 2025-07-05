#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n+1);
    vector<int> pa(n+1);
    pa[1]=-1;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        pa[i]=x;
        graph[x].push_back(i);
        graph[i].push_back(x);
    }
    vector<vector<int>> heirachy(n+1);
    function<void(int,int,int)> dfs=[&](int node,int fa,int c){
        heirachy[c].push_back(node);
        for(int next:graph[node]){
            if(next==fa) continue;
            dfs(next,node,c+1);
        }
    };
    dfs(1,-1,0);
    vector<int> dp(n+1);
    vector<int> tt(n+1);
    dp[1]=tt[0]=1;

    for(int c=1;c<=n;c++){

        for(int node:heirachy[c]){
            int papa=pa[node];
            dp[node]=tt[c-1];
            if(c>=2){
                dp[node]=(dp[node]-dp[papa]+M)%M;
            }
            tt[c]=(tt[c]+dp[node])%M;
        }
    }
    long long res=0;
    for(int i=0;i<=n;i++){
        res=(res+dp[i])%M;
    }
    cout<<res<<'\n';


    return;

}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}