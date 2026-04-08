#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>adj(n);
    for(int i=0;i<n;i++)adj[i]|=(1<<i);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u]|=(1<<v);
        adj[v]|=(1<<u);
    }
    int full=(1<<n)-1;
    vector<int>dom(1<<n,0);
    for(int ms=0;ms<(1<<n);ms++){
        for(int i=0;i<n;i++){
            if(ms&(1<<i))dom[ms]|=adj[i];
        }
    }
    vector<int>path;
    auto dfs=[&](auto& self,int u,int vis,int st,int ms)->bool{
        if(vis==ms)return (adj[u]&(1<<st))>0;
        int avail=ms&~vis&adj[u];
        while(avail){
            int v=__builtin_ctz(avail);
            path.push_back(v);
            if(self(self,v,vis|(1<<v),st,ms))return true;
            path.pop_back();
            avail&=avail-1;
        }
        return false;
    };
    for(int ms=1;ms<(1<<n);ms++){
        int k=__builtin_popcount(ms);
        if(k<=1)continue;
        if(dom[ms]!=full)continue;
        bool ok=true;
        int req=k==2?2:3;
        int tmp=ms;
        while(tmp){
            int i=__builtin_ctz(tmp);
            if(__builtin_popcount(adj[i]&ms)<req){
                ok=false;
                break;
            }
            tmp&=tmp-1;
        }
        if(!ok)continue;
        int reach=1<<__builtin_ctz(ms);
        int act=reach;
        while(act){
            int nxt=0,t=act;
            while(t){
                nxt|=adj[__builtin_ctz(t)]&ms;
                t&=t-1;
            }
            act=nxt&~reach;
            reach|=nxt;
        }
        if(reach!=ms)continue;
        int st=__builtin_ctz(ms);
        path={st};
        if(dfs(dfs,st,1<<st,st,ms)){
            vector<int>a(n);
            for(int i=0;i<k;i++)a[path[i]]=path[(i+1)%k];
            for(int i=0;i<n;i++){
                if(!(ms&(1<<i)))a[i]=__builtin_ctz(adj[i]&ms);
            }
            cout<<"Yes\n";
            for(int i=0;i<n;i++)cout<<a[i]+1<<(i==n-1?"":" ");
            cout<<"\n";
            return;
        }
    }
    cout<<"No\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1;
    while(t--)solve();
    return 0;
}