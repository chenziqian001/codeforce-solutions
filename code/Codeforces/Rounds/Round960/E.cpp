#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>>g(n+1);
    vector<int> fa(n+1),dep(n+1),tin(n+1),tout(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int timer=0;
    auto dfs=[&](auto self,int u,int p)->void{
        fa[u]=p;
        dep[u]=dep[p]+1;
        tin[u]=++timer;
        for(int v:g[u])if(v!=p)self(self,v,u);
        tout[u]=timer;
    };
    dep[0]=-1;
    dfs(dfs,1,0);
    auto is_anc=[&](int u,int v){
        return tin[u]<=tin[v]&&tout[u]>=tout[v];
    };

   vector<int>S;
    for(int i=1;i<=n;i++)S.push_back(i);
    vector<int>ord(n);
    iota(ord.begin(),ord.end(),1);
    sort(ord.begin(),ord.end(),[&](int a,int b){return dep[a]>dep[b];});
    int B=65;
    while(S.size()>1){
        sort(S.begin(),S.end(),[&](int a,int b){return dep[a]<dep[b];});
        bool chain=1;
        for(int i=0;i<(int)S.size()-1;i++){
            if(!is_anc(S[i],S[i+1])){
                chain=0;
                break;
            }
        }
        int q=-1;
        if(chain){
            q=S[S.size()/2];
        }else{
            vector<int>mx(n+1,-1);
            for(int u:S)mx[u]=dep[u];
            for(int u:ord){
                if(fa[u]&&mx[u]!=-1)mx[fa[u]]=max(mx[fa[u]],mx[u]);
            }
            int best=-1;
            for(int i=1;i<=n;i++){
                if(mx[i]!=-1&&mx[i]-dep[i]>=B){
                    if(best==-1||dep[i]>dep[best])best=i;
                }
            }
            if(best!=-1)q=best;
            else q=S.back();
        }
        cout<<"? "<<q<<endl;
        int res;
        cin>>res;
        if(res==-1)exit(0);
        vector<int>nS;
        if(res==1){
            for(int u:S)if(is_anc(q,u))nS.push_back(u);
        }else{
            for(int u:S)if(!is_anc(q,u))nS.push_back(max(1,fa[u]));
        }
        sort(nS.begin(),nS.end());
        nS.erase(unique(nS.begin(),nS.end()),nS.end());
        S=nS;
    }

    cout<<"! "<<S[0]<<endl;

}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}