#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
void solve(){
    int n,m,d;
    cin>>n>>m>>d;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(2)));
    vector<vector<vector<int>>> ps(n,vector<vector<int>>(m,vector<int>(2)));
    
    auto get_sum=[&](int i,int l,int r,int f){
        int  res=ps[i][r][f];
        if(l) res-=ps[i][l-1][f];
        return res;
    };
    
    auto get=[&](int i,int f,int j)->int{
        if(s[i][j]!='X') return 0;
        int res=0;
        if(i==n-1) res++;
        if(f){
            res+=get_sum(i,max(0LL,j-d),min(m-1,j+d),0);
            res-=dp[i][j][0];
        }
        if(i<n-1){
            res+=get_sum(i+1,max(0LL,j-d+1),min(m-1,j+d-1),1);
        }
        return res%mod;
    };
    for(int i=n-1;i>=0;i--){
        for(int f=0;f<2;f++){
            for(int j=0;j<m;j++){
                ps[i][j][f]=dp[i][j][f]=get(i,f,j);
            }
            for(int j=1;j<m;j++){
                ps[i][j][f]+=ps[i][j-1][f];
            }
        }
    }
    int res=0;
    for(int i=0;i<m;i++){
        res=(res+dp[0][i][1])%mod;
    }
    cout<<res<<'\n';
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}