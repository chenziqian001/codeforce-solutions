#include<bits/stdc++.h>
using namespace std;


const int N=1e6+10;

struct AC{
    int son[26],fail;
    int &operator [](int x){return son[x];};
};

AC ac[N];

vector<vector<int>> fail_t;

int n,m,k,l[N],r[N],top,cnt;
int ed[N];
long long fw[N];

char a[N];
int vis[N];


void getf(){
    fail_t.resize(top+1);
    queue<int> q;
    for(int i=0;i<26;i++){
        if(ac[0][i]) q.push(ac[0][i]);
    } 
    while(!q.empty()){
        int u=q.front();
        q.pop();

        fail_t[ac[u].fail].push_back(u);
        for(int i=0;i<26;i++){
            if(ac[u][i]){
                ac[ac[u][i]].fail=ac[ac[u].fail][i];
                q.push(ac[u][i]);
            }
            else{
                ac[u][i]=ac[ac[u].fail][i];
            }
        }
    }
}

void get_dfn(int u){
    l[u]=++cnt;
    for(int v:fail_t[u]){
        get_dfn(v);
    }
    r[u]=cnt;
}

void upd(int pos,int val){
    for(int i=pos;i<N;i+=(i&-i)) fw[i]+=val;
}
long long query(int pos){
    long long res=0;
    for(int i=pos;i>0;i-=i&-i){
        res+=fw[i];
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        string s;
        cin>>s;
        int cur=0;
        for(char c:s){
            if(!ac[cur][c-'a']){
                ac[cur][c-'a']=++top;
            }
            cur=ac[cur][c-'a'];
        }
        ed[i]=cur;
        vis[i]=1;
    }
    

    getf();
    get_dfn(0);
    for(int i=1;i<=k;i++){
        upd(l[ed[i]],1);
        upd(r[ed[i]]+1,-1);
    }


    while(n--){
        char op;
        cin>>op;
        if(op=='-'){
            int x;
            cin>>x;
            if(vis[x]){
                vis[x]=0;
                upd(l[ed[x]],-1);
                upd(r[ed[x]]+1,1);
            }
        }
        else if(op=='+'){
            int x;
            cin>>x;
            if(!vis[x]){
                vis[x]=1;
                upd(l[ed[x]],1);
                upd(r[ed[x]]+1,-1);
            }
        }
        else{
            string s;
            cin>>s;
            int len=s.size();
            long long cnt=0;
            int cur=0;
            for(int i=0;i<len;i++){
                cur=ac[cur][s[i]-'a'];
                cnt+=query(l[cur]);
            }
            cout<<cnt<<'\n';

        }
    }
    //system("pause");
    return 0;
}