/*
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+60;
int mp[N];
int in[N];
int p=0;

struct trie{
    int son[26];
    int fail;
    int ans;
    int tg;
    void clear(){
        for(int i=0;i<26;i++) son[i]=0;
        fail=ans=tg=0;
    }
}ac[N];

void build(string s,int id){
    int cur=0;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(!ac[cur].son[s[i]-'a']) ac[cur].son[s[i]-'a']=++p;
        cur=ac[cur].son[s[i]-'a'];
    }
    if(!ac[cur].tg) ac[cur].tg=id;
    mp[id]=ac[cur].tg;
}


void gf(){
    queue<int> q;
    for(int i=0;i<26;i++)ac[0].son[i]=1;
    q.push(1);
    while(!q.empty()){
        int u=q.front();q.pop();
        int Fail=ac[u].fail;
        for(int i=0;i<26;i++){
            int v=ac[u].son[i];
            if(!v){ac[u].son[i]=ac[Fail].son[i];continue;}
            ac[v].fail=ac[Fail].son[i]; in[ac[v].fail]++;
            q.push(v);
        }
    }
}
int res[N];

int topo(){
    queue<int> q;
    for(int i=1;i<=p;i++){
        if(in[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(!u) continue;
        res[ac[u].tg]=ac[u].ans;
        int v=ac[u].fail;
        if(!v) continue;
        in[v]--;
        ac[v].ans+=ac[u].ans;
        if(in[v]==0) q.push(v);
    }
}


void query(string s){
    int cur=0;
    int l=s.size();
    for(int i=0;i<l;i++){
        cur=ac[cur].son[s[i]-'a'];
        ac[cur].ans++;
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<26;i++){
        ac[0].son[i]=0;
    }
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        build(s,i);
    }
    gf();
    string ss;
    cin>>ss;
    query(ss);
    topo();
    for(int i=1;i<=n;i++){
        cout<<res[mp[i]]<<'\n';
    }
    //system("pause");
}
*/
//我根本不知道为什么在OJ上回REs
#include <bits/stdc++.h>
using namespace std;

const int N = 2000000 + 60;

int mp[N];        
int in[N];        
int res[N];       
int p = 0;    
struct trie {
    int son[26];
    int fail;
    int ans;      
    int tg;       
    void clear() {
        memset(son,0,sizeof(son));
        fail = ans = tg = 0;
    }
} ac[N];

void build(const string &s, int id){
    int cur = 0;                         
    for(char c : s){
        int v = c - 'a';
        if(!ac[cur].son[v]) ac[cur].son[v] = ++p;
        cur = ac[cur].son[v];
    }
    if(!ac[cur].tg) ac[cur].tg = id;      
    mp[id] = ac[cur].tg;
}


void gf(){
    queue<int> q;
    for(int i = 0; i < 26; i++){
        int v = ac[0].son[i];
        if(v){
            ac[v].fail = 0;
            q.push(v);
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < 26; i++){
            int v = ac[u].son[i];
            if(v){
                ac[v].fail = ac[ ac[u].fail ].son[i];
                in[ ac[v].fail ]++;
                q.push(v);
            }else{
                ac[u].son[i] = ac[ ac[u].fail ].son[i];
            }
        }
    }
}

void query(const string &s){
    int cur = 0;
    for(char c : s){
        cur = ac[cur].son[c - 'a'];
        ac[cur].ans++;
    }
}

void topo(){
    queue<int> q;
    for(int i = 1; i <= p; i++)
        if(in[i] == 0) q.push(i);

    while(!q.empty()){
        int u = q.front(); q.pop();
        if(ac[u].tg)
            res[ ac[u].tg ] = ac[u].ans;

        int v = ac[u].fail;
        if(v){
            in[v]--;
            ac[v].ans += ac[u].ans;
            if(in[v] == 0) q.push(v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    for(int i = 1; i <= n; i++){
        cin >> s;
        build(s, i);
    }
    gf();
    string T;
    cin >> T;
    query(T);
    topo();
    for(int i = 1; i <= n; i++)
        cout << res[ mp[i] ] << "\n";
    return 0;
}
