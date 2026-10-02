#include <bits/stdc++.h>
using namespace std;
#define int long long

struct E{
    int cu,cv,u,v;
    bool operator<(const E& o)const{
        if(cu!=o.cu) return cu<o.cu;
        return cv<o.cv;
    }
};

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> c(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    
    vector<vector<int>> g_in(n+1);
    vector<E> edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(c[u]==c[v]){
            g_in[u].push_back(v);
            g_in[v].push_back(u);
        }else{
            if(c[u]>c[v]) swap(u,v);
            edges.push_back({c[u],c[v],u,v});
        }
    }
    
    vector<int> comp(n+1),side(n+1,-1),bad(k+1,0);
    int cc=0;
    
    auto dfs1=[&](auto& self,int u,int cur_comp,int cur_side)->void{
        comp[u]=cur_comp;
        side[u]=cur_side;
        for(int v:g_in[u]){
            if(side[v]==-1){
                self(self,v,cur_comp,cur_side^1);
            }else if(side[v]==side[u]){
                bad[c[u]]=1;
            }
        }
    };
    
    for(int i=1;i<=n;i++){
        if(side[i]==-1){
            cc++;
            dfs1(dfs1,i,cc,0);
        }
    }
    
    int good_k=0;
    for(int i=1;i<=k;i++) if(!bad[i]) good_k++;
    int res=good_k*(good_k-1)/2;
    
    sort(edges.begin(),edges.end());
    int m_sz=edges.size();
    
    vector<vector<pair<int,int>>> gc(cc+1);
    vector<int> m_side(cc+1,-1);
    vector<int> touched;
    
    auto dfs2=[&](auto& self,int u,int c_side)->bool{
        m_side[u]=c_side;
        for(auto& p:gc[u]){
            int v=p.first,w=p.second;
            if(m_side[v]==-1){
                if(!self(self,v,c_side^w)) return false;
            }else if(m_side[v]!=(c_side^w)){
                return false;
            }
        }
        return true;
    };
    
    for(int i=0;i<m_sz;){
        int j=i;
        while(j<m_sz&&edges[j].cu==edges[i].cu&&edges[j].cv==edges[i].cv) j++;
        int cu=edges[i].cu,cv=edges[i].cv;
        
        if(!bad[cu]&&!bad[cv]){
            for(int idx=i;idx<j;idx++){
                int u=edges[idx].u,v=edges[idx].v;
                int cu_id=comp[u],cv_id=comp[v];
                int w=side[u]^side[v]^1;
                gc[cu_id].push_back({cv_id,w});
                gc[cv_id].push_back({cu_id,w});
                touched.push_back(cu_id);
                touched.push_back(cv_id);
            }
            
            bool ok=true;
            for(int idx=i;idx<j;idx++){
                int cu_id=comp[edges[idx].u];
                if(m_side[cu_id]==-1){
                    if(!dfs2(dfs2,cu_id,0)){
                        ok=false;
                        break;
                    }
                }
            }
            if(!ok) res--;
            
            for(int x:touched){
                gc[x].clear();
                m_side[x]=-1;
            }
            touched.clear();
        }
        i=j;
    }
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}