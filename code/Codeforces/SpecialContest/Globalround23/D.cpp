#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> son(n+1);
    for(int i=2;i<=n;i++){
        int pa;
        cin>>pa;
        son[pa].push_back(i);
    }
   


    vector<vector<int>> f(n+1,vector<int>(2));
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) cin>>s[i];
    
    function<void(int,int)> dfs=[&](int node,int cur){
        int deg=son[node].size();
        if(!deg){
            f[node][0]=cur*s[node];
            f[node][1]=(cur+1)*s[node];
            return;
        }
        int sum=0;
        vector<int> diff;
        for(int next:son[node]){
            dfs(next,cur/deg);
            sum+=f[next][0];
            diff.push_back(f[next][1]-f[next][0]);
        }
        sort(diff.rbegin(),diff.rend());
        int re=cur%deg;
        f[node][0]=cur*s[node]+sum;
        for(int i=0;i<re;i++) f[node][0]+=diff[i];
        f[node][1]=(cur+1)*s[node]+sum;
        for(int i=0;i<=re;i++) f[node][1]+=diff[i];
    };
    dfs(1,k);
    cout<<f[1][0]<<'\n';
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
