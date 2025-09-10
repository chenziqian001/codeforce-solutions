#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define int long long
const int N=1e6+10;
vector<vector<int>> power(N,vector<int>(21));
void init(){
    for(int i=0;i<N;i++){
        power[i][0]=1;
        for(int j=1;j<=20;j++){
            power[i][j]=power[i][j-1]*i%mod;
        }
    }
}

int cg(int a,int p){
    return (a>>(p+1)<<p)|(a&((1<<p)-1));
}

void solve(){
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    vector<int> vali(n);
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        x--;
        vali[x]=1;
    }
    if(m==1){
        cout<<1<<'\n';
        return;
    }
    vector<vector<int>> dp(n+1);
    dp[1].resize(1<<1);
    dp[1][0]=0;
    dp[1][1]=1;
    for(int i=2;i<=n;i++){
        dp[i].resize(1<<i);
        for(int j=0;j<(1<<i);j++){
            if((n-i)%2==0) dp[i][j]=0;
            else dp[i][j]=1;

            for(int p=0;p<i;p++){
                if(!vali[p]) continue;
                int ns=cg(j,p);
                if(dp[i][j]!=dp[i-1][ns]){
                    dp[i][j]=dp[i-1][ns];
                    break;
                }
            }
        }
    }
    vector<int> cnt(n+1,0);
    for(int i=0;i<(1<<n);i++){
        if(dp[n][i]==1){
            int r=__builtin_popcount(i);
            cnt[r]++;
        }
    }
    int res=0;
    for(int r=0;r<=n;r++){
        for(int j=1;j<=m;j++){
            int left=power[j-1][n-r];
            int right=power[m-j+1][r];
            res=(res+left*right%mod*cnt[r]%mod)%mod;
        }
    }
    cout<<res<<'\n';
}
signed main()
{
    init();
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}

