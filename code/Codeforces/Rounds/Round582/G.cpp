#include<bits/stdc++.h>
using namespace std;
#define int long long 


struct E{
    int u,v,w;
    bool operator<(struct E &o) const{
        return w<o.w;
    };
};



void solve(){
    int n,m;
    cin>>n>>m;
    vector<E> e(n-1);
    for(int i=0;i<n-1;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }

    vector<pair<int,int>> q(m);
    for(int i=0;i<m;i++){
        cin>>q[i].first;
        q[i].second=i;
    }
    sort(q.begin(),q.end());
    sort(e.begin(),e.end());

    int res=0;
    vector<int> fa(n+1);
    iota(fa.begin(),fa.end(),0);
    vector<int> sz(n+1,1);
    auto find=[&](auto self,int x)->int{
        return fa[x]==x?x:fa[x]=self(self,fa[x]);
    }; 

    int id=0;
    vector<int> ans(m+1);
    for(int i=0;i<m;i++){
        while(id<n-1 && e[id].w<=q[i].first){
            int u=e[id].u;
            int v=e[id].v;
            int ru=find(find,u),rv=find(find,v);
            if(ru!=rv){
                res+=sz[ru]*sz[rv];
                fa[rv]=ru;
                sz[ru]+=sz[rv];
                
            }
            id++;
        }
        ans[q[i].second]=res;
    }


    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';





}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}

