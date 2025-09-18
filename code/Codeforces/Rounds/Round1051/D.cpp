#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
/*void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1)));
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                if(!dp[i-1][j][k]) continue;
                dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k])%mod;
                if(a[i]<k) continue;
                if(a[i]>=j){
                    dp[i][a[i]][k]=(dp[i][a[i]][k]+dp[i-1][j][k])%mod;
                }
                else dp[i][j][a[i]]=(dp[i][j][a[i]]+dp[i-1][j][k])%mod;
            }
        }
    }
    long long res=0;
    for(int j=0;j<=n;j++){
        for(int k=0;k<=j;k++){
            res=(res+dp[n][j][k])%mod;
        }
    }
 
    cout<<res<<'\n';
}*/
int n;
const int N=2005;
int rt[N][N],ct[N][N];
void radd(int row,int i,int val){
    i++;
    for(;i<=n+1;i+=i&-i){
        rt[row][i]=(rt[row][i]+val)%mod;
    }
}
void cadd(int col,int i,int val){
    i++;
    for(;i<=n+1;i+=i&-i){
        ct[col][i]=(ct[col][i]+val)%mod;
    }
}
int rq(int row,int i){
    i++;
    int res=0;
    for(;i>=1;i-=i&-i) res=(res+rt[row][i])%mod;
    return res;
}
int cq(int col,int i){
    i++;
    int res=0;
    for(;i>=1;i-=i&-i) res=(res+ct[col][i])%mod;
    return res;
}
void solve(){
    cin>>n;
    vector<int> b(n+1);
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        a[i]=1;
        for(int j=1;j<i;j++){
            if(b[j]<=b[i]) a[i]++;
        }
        for(int j=i+1;j<=n;j++){
            if(b[j]<b[i]) a[i]++;
        }
    }
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            rt[i][j] = ct[i][j] = 0;
 
    radd(0,0,1);
    cadd(0,0,1);
    for(int i=1;i<=n;i++){
        int x=a[i];
        vector<pair<int,pair<int,int>>> buffs;
        for(int r=x+1;r<=n;r++){
            int row,col,buff;
            row=r;
            col=x;
            buff=rq(row,col-1);
            buffs.push_back({buff,{row,col}});
        }
        for(int c=0;c<x;c++){
            int row,col,buff;
            row=x;
            col=c;
            buff=cq(col,row-1);
            buffs.push_back({buff,{row,col}});
        }
        for(auto it:buffs){
            radd(it.second.first,it.second.second,it.first);
            cadd(it.second.second,it.second.first,it.first);
        }
 
    }
    int res=0;
    for(int i=0;i<=n;i++){
        res=(res+rq(i,n))%mod;
    }
    cout<<res<<'\n';
 
 
}
 
 
 
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}
