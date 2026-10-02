#include<bits/stdc++.h>
using namespace std;
#define int long long

struct e{
    int u,v,w;
    bool operator<(const e& o)const{
        return w<o.w;
    }
};

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    set<int> st;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        st.insert(x);
    }    
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> fa(n+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    int blk=n;
    auto find=[&](auto &self,int u)->int{
        return fa[u]==u?u:fa[u]=self(self,fa[u]);
    };
    auto merge=[&](int u,int v)->bool{
        u=find(find,u);
        v=find(find,v);
        if(u==v) return false;
        else{
            blk--;
            fa[u]=v;
            return true;
        }
    };
    vector<e> g;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        if(st.count(u) || st.count(v)) continue;
        g.push_back({u,v,w});
    }
    if(n==k){
        if(n==2 && m>0){
            int min_w=1e18;
            for(auto [v,w]:adj[1]) min_w=min(min_w,w);
            cout<<(min_w==1e18?-1:min_w)<<'\n';
        }else{
            cout<<-1<<'\n';
        }
        return;
    }
    sort(g.begin(),g.end());
    int res=0;
    for(auto E:g){
        int u=E.u,v=E.v;
        if(merge(u,v)){
            res+=E.w;
        }
    }
    if(n!=k && blk!=(int)st.size()+1){
        cout<<-1<<'\n';
        return;
    }

    for(int x:st){
        bool ok=false;
        int val=1e18;
        for(auto [v,w]:adj[x]){
            if(st.count(v)) continue;
            ok=true;
            val=min(val,w);
        }
        if(!ok){
            cout<<-1<<'\n';
            return;
        }
        else{
            res+=val;
        }
    }

    cout<<res<<'\n';
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

