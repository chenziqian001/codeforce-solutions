#include<bits/stdc++.h>
using namespace std;
 
const int inf=1e9;
int n,k;
int u[4005][4005];
int w[4005][4005];
int opt[810][4010];
vector<vector<int>> dp;
/*
void compute(int g,int L,int R,int optl,int optr){
    if(L>R) return;
    int mid=(L+R)/2;
    pair<int,int> best={inf,-1};
    for(int i=optl;i<=min(mid-1,optr);i++){
        int val=dp[g-1][i]+w[i+1][mid];
        if(val<best.first) best={val,i};
    }
    dp[g][mid]=best.first;
    int optm=best.second;
    compute(g,L,mid-1,optl,optm);
    compute(g,mid+1,R,optm,optr);
}
*/
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
   
   for(int i=1,x;i<=n;++i)
        for(int j=1;j<=n;++j){
            int x;
            cin>>x;
            if(i<j)w[i][j]+=x;
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n-1;++j)
            w[i][j+1]+=w[i][j];
    for(int i=n;i>=2;--i)
        for(int j=1;j<=n;++j)
            w[i-1][j]+=w[i][j];
    dp.resize(k+1,vector<int>(n+1,inf));
    for(int i=1;i<=n;i++) dp[1][i]=w[1][i],opt[1][i]=1;
    for(int i=2;i<=k;i++){
        opt[i][n+1]=n;
        for(int j=n;j>=1;j--){
            opt[i][j]=1;
            for(int k=opt[i-1][j];k<=min(j,opt[i][j+1]);k++){
                if(dp[i-1][k-1]+w[k][j]<dp[i][j]){
                    dp[i][j]=dp[i-1][k-1]+w[k][j];
                    opt[i][j]=k;
                }
            }
        }
    }
    
    cout<<dp[k][n]<<'\n';
    
 
}