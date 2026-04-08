#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> fa(n+1,0),sz(n+1,1),son(n+1,0),dep(n+1,1);
    sz[0]=0;
    vector<vector<int>> up(20,vector<int>(n+1,0));
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++){
        cin>>fa[i];
        adj[fa[i]].push_back(i);
        dep[i]=dep[fa[i]]+1;
        up[0][i]=fa[i];
        for(int j=1;j<20;j++) up[j][i]=up[j-1][up[j-1][i]];
    }

    for(int i=n;i>=2;i--){
        sz[fa[i]]+=sz[i];
        if(sz[i]>sz[son[fa[i]]]) son[fa[i]]=i;
    }


    vector<int> top(n+1,1),in(n+1),out(n+1),offset(n+1,1);
    for(int i=2;i<=n;i++)top[i]=(son[fa[i]]==i)?top[fa[i]]:i;

    int timer=0;
    auto dfs=[&](auto self,int u)->void{
        in[u]=++timer;
        if(son[u])self(self,son[u]);
        for(int v:adj[u])if(v!=son[u])self(self,v);
        out[u]=timer;
    };
    dfs(dfs,1);

    vector<int> bit(n+1);
    auto add=[&](int pos,int val){for(;pos<=n;pos+=pos&-pos) bit[pos]+=val;};
    auto query=[&](int pos){int res=0;for(;pos>0;pos-=pos&-pos){res+=bit[pos];}return res;};
    auto W=[&](int u){return u?query(out[u])-query(in[u]-1):0;};

    vector<priority_queue<int>> q(n+1),del(n+1);
    
    int c=1;
    add(in[1],1);
    for(int i=2;i<=n;i++){
        int u=i,S=i,cur=u;
        while(cur>0){
            int h=top[cur],p=fa[h];
            if(p>0)del[p].push(W(h));
            cur=p;
        }

        add(in[u],1);
        cur=u;
        while(cur){
            int h=top[cur];
            int p=fa[h];
            if(p) q[p].push(W(h));
            cur=p;
        }

        while(1){
            if(in[c]<=in[u]&&in[u]<=out[c]){
                int d=dep[u]-dep[c]-1;
                int nxt=u;
                if(d<0) break;
                for(int j=19;j>=0;j--){if(d>>j&1) nxt=up[j][nxt];}

                if(W(nxt)>S/2) c=nxt;
                else break;
            }
            else{
                int p=fa[c];
                if(S-W(c)>S/2) c=p;
                else break;
            }
        }

        int M=max({0LL,c!=1?S-W(c):0LL,W(son[c])});
        while(q[c].size()&&del[c].size()&&q[c].top()==del[c].top()){
            q[c].pop();
            del[c].pop();
        }
        if(q[c].size()) M=max(M,q[c].top());
        cout<<S-2*M<<" ";
    }
    cout<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}