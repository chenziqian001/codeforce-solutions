#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;


void solve(){
    int n,k;
    cin>>n>>k;
    string p,pos;
    cin>>p>>pos;
    int m=p.size();

    string s(n,'?');
    for(int i=0;i<=n-m;i++){
        if(pos[i]=='1'){
            for(int j=0;j<m;j++){
                if(s[i+j]!='?'&&s[i+j]!=p[j]){
                    cout<<"No solution"<<'\n';
                    return;
                }
                s[i+j]=p[j];
            }
        }
    }


    vector<int> pi(m+1);
    for(int i=1,j=0;i<m;i++){
        while(j && p[i]!=p[j]) j=pi[j];
        if(p[i]==p[j]) j++;
        pi[i+1]=j;
    }
    vector<vector<int>> tran(m+1,vector<int>(k));
    for(int j=0;j<=m;j++){
        for(int c=0;c<k;c++){
            int cur=j;
            while(cur && p[cur]!=(char)('a'+c)) cur=pi[cur];
            if(p[cur]==(char)('a'+c)) tran[j][c]=cur+1;
            else tran[j][c]=0;
        }
    }

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<vector<int>> ch(n+1,vector<int>(m+1,0));
    for(int i=0;i<=m;i++)dp[n][i]=1;


    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=m;j++){
            if(s[i]!='?'){
               
                int c=s[i]-'a';
                int ns=tran[j][c];
                if(ns==m && pos[i-m+1]=='0')dp[i][j]=0;
                else dp[i][j]=dp[i+1][ns];
            }else{
                for(int c=0;c<k;c++){
                    int ns=tran[j][c];
                    if(ns==m && pos[i-m+1]=='0')continue;
                    if(dp[i+1][ns]){
                        dp[i][j]=1;
                        ch[i][j]=c;
                        break;
                    }
                }
            }
        }
    }

    if(!dp[0][0]){
        cout<<"No solution"<<'\n';
        return;
    }
    int st=0;
    for(int i=0;i<n;i++){
        int c;
        if(s[i]!='?') c=s[i]-'a';
        else c=ch[i][st];
        cout<<char('a'+c);
        st=tran[st][c]; 
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
}