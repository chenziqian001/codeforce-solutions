#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    vector<int> pi(m+1);
    for(int i=1;i<=m;i++){
        int j=pi[i-1];
        while(j>0 && t[i]!=t[j]) j=pi[j-1];
        if(t[i]==t[j]) j++;
        pi[i]=j;
    }

    vector<vector<int>> next(m+1,vector<int>(26));
    for(int i=0;i<=m;i++){
        for(int c=0;c<26;c++){
            if(i>0 &&(('a'+c)!=t[i])){
                next[i][c]=next[pi[i-1]][c];
            }
            else next[i][c]=i+(('a'+c)==t[i]);
        }
    }

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(dp[i-1][j]==-1) continue;
            if(s[i-1]!='?'){
                int c=s[i-1]-'a';
                int nj=next[j][c];
                int add=(nj==m);
                dp[i][nj]=max(dp[i][nj],dp[i-1][j]+add);
            }
            else{
                for(int c=0;c<26;c++){
                    int nj=next[j][c];
                    int add=(nj==m);
                    dp[i][nj]=max(dp[i][nj],dp[i-1][j]+add);
                }

            }
        }
    }

    int ans=0;
    for(int j=0;j<=m;j++){
        ans=max(ans,dp[n][j]);
    }

    cout<<ans<<'\n';
    return;
}



int main(){
    solve();
    system("pause");
    return 0;
}