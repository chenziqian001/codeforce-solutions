#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int R,G,B;
    cin>>R>>G>>B;
    vector<int> r(R),g(G),b(B);
    for(int i=0;i<R;i++)cin>>r[i];
    for(int i=0;i<G;i++)cin>>g[i];
    for(int i=0;i<B;i++)cin>>b[i];
    sort(r.rbegin(),r.rend());
    sort(g.rbegin(),g.rend());
    sort(b.rbegin(),b.rend());
    vector<vector<vector<int>>> dp(R+1,vector<vector<int>>(G+1,vector<int>(B+1,-1)));
    function<int(int,int,int)> f=[&](int i,int j,int k){
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int res=0;
        if(i<R&&j<G)res=max(res,r[i]*g[j]+f(i+1,j+1,k));
        if(i<R&&k<B)res=max(res,r[i]*b[k]+f(i+1,j,k+1));
        if(j<G&&k<B)res=max(res,g[j]*b[k]+f(i,j+1,k+1));
        return dp[i][j][k]=res;
    };
    cout<<f(0,0,0)<<'\n';
    
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}