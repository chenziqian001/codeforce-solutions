#include<bits/stdc++.h>
using namespace std;
const int N=500;
const int inf=-1e9;

struct trie{
    int son[26];
    int fail;
    int tg;
}ac[N];
int p=0;
void build(string s,int tg){
    int l=s.size();
    int cur=0;
    for(int i=0;i<l;i++){
        if(ac[cur].son[s[i]-'a']==0) ac[cur].son[s[i]-'a']=++p;
        cur=ac[cur].son[s[i]-'a']; 
    }
    ac[cur].tg=tg;
}

void getf(){
    queue<int> q;
    for(int i=0;i<26;i++){
        if(ac[0].son[i]){
            ac[ac[0].son[i]].fail=0;
            q.push(ac[0].son[i]);
        }
    }
   
 
    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0;i<26;i++){
            int v=ac[u].son[i];
            if(v){
                ac[v].fail=ac[ac[u].fail].son[i];
                ac[v].tg += ac[ac[v].fail].tg;
                q.push(v);
            }
            else{
                ac[u].son[i]=ac[ac[u].fail].son[i];
            }
        }
    }


    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string c;
    cin>>c;


    string s;
    string t;
    cin>>s;
    cin>>t;
    build(s,1);
    build(t,-1);
    getf();

    int n=c.size();
    vector<vector<int>> dp(n+1,vector<int>(p+1,inf));
    dp[0][0]=0;


    for(int i=0;i<n;i++){
        for(int st=0;st<=p;st++){
            if(dp[i][st]==inf) continue;
            if(c[i]=='*'){
                for(int j=0;j<26;j++){
                    int nxt=ac[st].son[j];
                    dp[i+1][nxt]=max(dp[i+1][nxt],dp[i][st]+ac[nxt].tg);
                }
            }
            else{
                int k=c[i]-'a';
                int nxt=ac[st].son[k];
                dp[i+1][nxt]=max(dp[i+1][nxt],dp[i][st]+ac[nxt].tg);
            }
        }
    }

    int res=inf;
    for(int st=0;st<=p;st++){
        res=max(res,dp[n][st]);
    }
    cout<<res<<'\n';
    //system("pause");
}