#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
void add(long long &a,long long b){
    a=a+b;
    if(a>=mod) a-=mod;
}
void sub(long long &a,long long b){
    a=a-b;
    if(a<0) a+=mod;
}
void solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    s=' '+s;
    int cnt=0;
    vector<vector<vector<vector<long long>>>> dp(2,vector<vector<vector<long long>>>(n+1,vector<vector<long long>>(n+1,vector<long long>(3))));
    if(s[1]=='?'){
        cnt++;
        dp[1][1][0][0]=1;
        dp[1][0][1][1]=1;
        dp[1][0][0][2]=1;
    }
    else{
        if(s[1]=='a') dp[1][0][0][0]=1;
        if(s[1]=='b') dp[1][0][0][1]=1;
        if(s[1]=='c') dp[1][0][0][2]=1;
    }
    for(int i=2;i<=n;i++){
        if(s[i]=='?') cnt++;
        for(int j=0;j<=cnt;j++){
            for(int k=0;k+j<=cnt;k++){
                for(int x=0;x<3;x++) dp[i&1][j][k][x]=0;
            }
        }
        for(int j=0;j<=cnt;j++){
            for(int k=0;k+j<=cnt;k++){
                for(int x=0;x<3;x++){
                    if(s[i]=='?'){
                        if(j && x!=0) add(dp[i&1][j][k][0],dp[(i-1)&1][j-1][k][x]);
                        if(k && x!=1) add(dp[i&1][j][k][1],dp[(i-1)&1][j][k-1][x]);
                        if(x!=2) add(dp[i&1][j][k][2],dp[(i-1)&1][j][k][x]);
                    }
                    else{
                        if(s[i]=='a' && x!=0) add(dp[i&1][j][k][0],dp[(i-1)&1][j][k][x]);
                        if(s[i]=='b' && x!=1) add(dp[i&1][j][k][1],dp[(i-1)&1][j][k][x]);
                        if(s[i]=='c' && x!=2) add(dp[i&1][j][k][2],dp[(i-1)&1][j][k][x]);
                    }
                }
            }
        } 
    }

    vector<vector<vector<long long>>> prefix(n+1,vector<vector<long long>>(n+1,vector<long long>(n+1)));
    for(int i=0;i<=cnt;i++){
        for(int j=0;j+i<=cnt;j++){
            for(int x=0;x<3;x++){
                add(prefix[i][j][cnt-i-j],dp[n&1][i][j][x]);
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                if(i>=1) add(prefix[i][j][k],prefix[i-1][j][k]);
                if(j>=1) add(prefix[i][j][k],prefix[i][j-1][k]);
                if(k>=1) add(prefix[i][j][k],prefix[i][j][k-1]);
                if(i>=1 && j>=1) sub(prefix[i][j][k],prefix[i-1][j-1][k]);
                if(i>=1 && k>=1) sub(prefix[i][j][k],prefix[i-1][j][k-1]);
                if(j>=1 && k>=1) sub(prefix[i][j][k],prefix[i][j-1][k-1]);
                if(i>=1 && j>=1 && k>=1) add(prefix[i][j][k],prefix[i-1][j-1][k-1]);
            }
        }
    }

    while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        cout<<prefix[x][y][z]<<'\n';
    }
}
int main(){
    solve();
    system("pause");
    return 0;
}