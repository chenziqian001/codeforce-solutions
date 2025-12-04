#include<bits/stdc++.h>
using namespace std;
const int N=1000;
struct trie{
    int son[26];
    int fail;
    int len;
    bool end;
}ac[N];
int p=0;
void build(string s){
    int l=s.size();
    int cur=0;
    for(int i=0;i<l;i++){
        if(ac[cur].son[s[i]-'a']==0) ac[cur].son[s[i]-'a']=++p;
        cur=ac[cur].son[s[i]-'a'];
    }
    ac[cur].len=s.size();
    ac[cur].end=true;
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
                q.push(v);
            }
            else ac[u].son[i]=ac[ac[u].fail].son[i];
        }
    }
}
void solve(){
    string s;
    cin>>s;
    int l=s.size();
    vector<bool> dp(l+1,false);
    dp[0]=true;
    int cur=0;
    int mx_len=0;
    for(int i=0;i<l && i-mx_len<=20;i++){
        cur=ac[cur].son[s[i]-'a'];
        int temp=cur;
        while(temp){
            if(ac[temp].end && dp[i+1-ac[temp].len]){
                dp[i+1]=true;
                mx_len=i+1;
                break;
            }
            temp=ac[temp].fail;
        }
    }
    cout<<mx_len<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        build(s);
    }
    getf();
    while(m--) solve();
    //system("pause");
}
/*
4 3 
is
name
what
your
whatisyourname
whatisyouname
whaisyourname
*/