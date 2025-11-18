#include<bits/stdc++.h>
using namespace std;


int n;
const int N=2e5+10;
int a[N];
int b[N];
vector<int> g[N];
set<int> st[N];
int res;


void init(int node,int fa){
    b[node]=a[node];
    if(fa!=-1) b[node]^=b[fa];
    for(int next:g[node]){
        if(next==fa) continue;
        init(next,node);
    }
}

void dfs(int node,int fa){
    st[node].insert(b[node]);
    int bad=0;
    for(int next:g[node]){
        if(next==fa) continue;
        dfs(next,node);
        if(st[next].size()>st[node].size()) swap(st[next],st[node]);
        for(int x:st[next]){
            bad|=st[node].count(x^a[node]);
        }
        for(int x:st[next]) st[node].insert(x);
    }
    if(bad){
        res++;
        st[node].clear();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    res=0;


    init(0,-1);
    dfs(0,-1);
    cout<<res<<'\n';

    //system("pause");
    
}