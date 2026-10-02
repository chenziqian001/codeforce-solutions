#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int> g[N];
int a[N],b[N];
int ca[N],cb[N];
int tt;
bool marked[N];
int res[N];


void upd(int val,int tp,int delta){
    if(val==0) return;
    tt-=max(ca[val],cb[val]);
    if(tp==0) ca[val]+=delta;
    else cb[val]+=delta;
    tt+=max(cb[val],ca[val]);
}

void calc(int node,int fa,int delta){
    upd(a[node],0,delta);
    upd(b[node],1,delta);
    for(int next:g[node]){
        if(next!=fa && !marked[next]){
            calc(next,node,delta);
        }
    }
}
int sz[N];
int son[N];
void init(int node,int fa){
    sz[node]=1;
    son[node]=-1;
    int mx=-1;
    for(int next:g[node]){
        if(next==fa) continue;
        init(next,node);
        sz[node]+=sz[next];
        if(sz[next]>mx){
            mx=sz[next];
            son[node]=next;
        }
    }
}

void dfs(int node,int fa,bool keep){
    for(int next:g[node]){
        if(next==fa || next==son[node]) continue;
        dfs(next,node,false);
    }

    if(son[node]!=-1){
        dfs(son[node],node,true);
        marked[son[node]]=true;
    }
    calc(node,fa,1);

    if(tt<=sz[node]) res[node]=1;
    else res[node]=0;

    if(son[node]!=-1){
        marked[son[node]]=false;
    }
    
    if(!keep){
        calc(node,fa,-1);
    }

}


void cl(int n){
    for(int i=0;i<n;i++){
        g[i].clear();
        ca[i]=cb[i]=0;
        tt=0;
        marked[i]=false;
    }
}



void solve(){
    int n;
    cin>>n;
    cl(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];


    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    init(0,-1);
    dfs(0,-1,false);
    
    for(int i=0;i<n;i++){
        cout<<res[i];
    }
    cout<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}

