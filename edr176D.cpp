#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long inf=1e18;
long long dp[60][60];
void solve(){
    long long x,y;
    cin>>x>>y;
    long long res=inf;

    for(int i=0;i<60;i++){
        for(int j=0;j<60;j++){
            if((x>>i)==(y>>j)) res=min(res,dp[i][j]);
        }
    }

    cout<<res<<'\n';
    
    return ;
}

int main(){
    int t;
    cin>>t;
    
    for(int i=0;i<60;i++){
        for(int j=0;j<60;j++){
            dp[i][j]=inf;
        }
    }
    dp[0][0]=0;
    for(int x=0;x<60;x++){
        for(int i=59;i>=0;i--){
            for(int j=59;j>=0;j--){
                if(dp[i][j]==inf) continue;
                if(i+x<60) dp[i+x][j]=min(dp[i+x][j],dp[i][j]+(1LL<<x));
                if(j+x<60) dp[i][j+x]=min(dp[i][j+x],dp[i][j]+(1LL<<x));
            }
        }
    }
    while(t--) solve();
    system("pause");
    return 0;
}