#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+9;
const int N=10000;



struct trie{
    int son[4];
    int fail;
    int len;
}ac[N];

int f(char c){
    if(c=='A') return 0;
    if(c=='G') return 1;
    if(c=='C') return 2;
    return 3;
}
int p=0;

void build(string s){
    int l=s.size();
    int cur=0;
    for(char c:s){
        if(ac[cur].son[f(c)]==0){
            ac[cur].son[f(c)]=++p;
        }
        cur=ac[cur].son[f(c)];
    }
    ac[cur].len=s.size();
}

void getf(){
    queue<int> q;
    for(int i=0;i<4;i++){
        if(ac[0].son[i]){
            ac[ac[0].son[i]].fail=0;
            q.push(ac[0].son[i]);
        }
    }

    while(!q.empty()){
        int u=q.front();
        q.pop();
        ac[u].len=max(ac[u].len,ac[ac[u].fail].len);
        for(int i=0;i<4;i++){
            int v=ac[u].son[i];
            if(v){
                ac[v].fail=ac[ac[u].fail].son[i];
                q.push(v);
            }
            else ac[u].son[i]=ac[ac[u].fail].son[i];
        }
    }
}




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        string s;cin>>s;
        build(s);
    }
    getf();

    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(p+10,vector<int>(13)));
    dp[0][0][0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<=p;j++){
            for(int k=0;k<=10;k++){

                for(int c=0;c<4;c++){
                    int nx=ac[j].son[c];
                    if(ac[nx].len>k){
                        dp[i+1][nx][0]=(dp[i+1][nx][0]+dp[i][j][k])%mod;
                    }
                    else{
                        dp[i+1][nx][k+1]=(dp[i+1][nx][k+1]+dp[i][j][k])%mod;   
                    }
                }
            }
        }

    }
    int res=0;
    for(int i=0;i<=p;i++){
        res=(res+dp[n][i][0])%mod;
    }
    cout<<res<<'\n';
    //system("pause");
}

