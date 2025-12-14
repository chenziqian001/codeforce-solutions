#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=2e5+10;
int ls[N],rs[N];
vector<vector<int>> f;
int n,m;
void dfs(int node){
    f[node][0]=0;
    for(int i=1;i<=m;i++) f[node][i]=1;
    if(ls[node]) dfs(ls[node]);
    if(rs[node]) dfs(rs[node]);
    if(ls[node]) for(int i=1;i<=m;i++) f[node][i]=f[node][i]*f[ls[node]][i-1]%mod;
    if(rs[node]) for(int i=1;i<=m;i++) f[node][i]=f[node][i]*f[rs[node]][i]%mod;
    for(int i=2;i<=m;i++) f[node][i]=(f[node][i]+f[node][i-1])%mod;
}



void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) ls[i]=rs[i]=0;
    f.assign(n+1, vector<int>(m+1, 0));
    vector<int> a(n+1);
    int mx=0;
    int root=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>mx){
            root=i;
            mx=a[i];
        }
    }
    stack<int> st;

    for(int i=1;i<=n;i++){
        int x=a[i];
        int last=-1;
        while(!st.empty() && x>a[st.top()]){
            last=st.top();
            st.pop();
        }
        if(last!=-1){
            ls[i]=last;
        }
        if(!st.empty()) rs[st.top()]=i;
        st.push(i);
    }

    dfs(root);
    cout<<f[root][m]<<'\n';

    

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