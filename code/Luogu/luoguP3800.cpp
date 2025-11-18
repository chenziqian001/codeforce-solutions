#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5;
int q[N];

/*
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k,t;
    cin>>n>>m>>k>>t;

    vector<vector<int>> g(n,vector<int>(m));
    for(int i=0;i<k;i++){
        int x,y,v;
        cin>>x>>y>>v;
        x--,y--;
        g[x][y]=v;
    }

    vector<vector<int>> dp(2,vector<int>(m));
    for(int j=0;j<m;j++) dp[0][j]=g[0][j];
    int p=0;
    for(int i=1;i<n;i++){
        p^=1;
        for(int j=0;j<m;j++){
            dp[p][j]=0;
        }
        int l=1,r=0;
        for(int j=0;j<t;j++){
            while(l<=r && dp[p^1][q[r]]<=dp[p^1][j]) r--;
            q[++r]=j;
        }
        for(int j=0;j<m;j++){
            if(j+t<m){
                while(l<=r && dp[p^1][q[r]]<=dp[p^1][j+t]) r--;
                q[++r]=j+t;
            }
            while(l<=r && q[l]<j-t) l++;
            dp[p][j]=max(dp[p][j],dp[p^1][q[l]]+g[i][j]);
        }
    }

    int res=0;
    for(int j=0;j<m;j++){
        res=max(res,dp[p][j]);
    }
    cout<<res<<'\n';
    //system("pause");
}
*/
//以上是单调队列优化的做法
//接下来展示st表(稀疏表)的做法

int f[N][20];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k,t;
    cin>>n>>m>>k>>t;

    vector<vector<int>> g(n,vector<int>(m));
    for(int i=0;i<k;i++){
        int x,y,v;
        cin>>x>>y>>v;
        x--,y--;
        g[x][y]=v;
    }

    vector<vector<int>> dp(2,vector<int>(m));
    for(int j=0;j<m;j++) dp[0][j]=g[0][j];
    int p=0;

    for(int i=1;i<n;i++){
        p^=1;
        
        for(int j=0;j<m;j++){
            f[j][0]=dp[p^1][j];
        }
        for(int k=1;k<20;k++){
            for(int l=0;l+(1<<k)-1<m;l++){
                f[l][k]=max(f[l+(1<<(k-1))][k-1],f[l][k-1]);
            }
        }
        for(int j=0;j<m;j++){
            auto query=[&](int l,int r){
                int k=__lg(r-l+1);
                return max(f[l][k],f[r-(1<<k)+1][k]);
            };
            dp[p][j]=query(max(0LL,j-t),min(m-1,j+t))+g[i][j];
        }
    }
    int res=0;
    for(int j=0;j<m;j++){
        res=max(res,dp[p][j]);
    }
    cout<<res<<'\n';
    //system("pause");
}



