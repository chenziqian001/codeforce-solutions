#include<bits/stdc++.h>
using namespace std;
struct C{int u,d;long long R;};
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> f(n+1);
    vector<vector<int>> e(n+1);
    for(int i=2;i<=n;i++){
        cin>>f[i];
        e[f[i]].push_back(i);
    }
    vector<long long> l(n+1),D(n+1);
    for(int i=2;i<=n;i++){
        cin>>l[i];
        D[i]=D[f[i]]+l[i];
    }
    vector<long long> qs(q);
    for(int i=0;i<q;i++) cin>>qs[i];
    vector<int> sz(n+1,1),hc(n+1,-1),id(n+1,-1);
    for(int i=n;i>=2;i--) sz[f[i]]+=sz[i];
    for(int i=1;i<=n;i++){
        int m=-1;
        for(int j=0;j<e[i].size();j++){
            int v=e[i][j];
            if(sz[v]>m){
                m=sz[v];
                hc[i]=v;
                id[i]=j;
            }
        }
    }
    vector<int> top(n+1),bot(n+1);
    top[1]=1;
    for(int i=2;i<=n;i++) top[i]=(hc[f[i]]==i)?top[f[i]]:i;
    for(int i=n;i>=1;i--) bot[i]=(hc[i]!=-1)?bot[hc[i]]:i;
    vector<vector<C>> cand(n+1);
    vector<long long> fir(n+1,-1);
    vector<bool> sec(n+1,false);
    for(int i=1;i<=n;i++){
        if(top[i]==i){
            int u=i;
            vector<int> t;
            while(hc[u]!=-1){
                int d=e[u].size();
                long long R=(id[u]-D[u])%d; 
                if(R<0) R+=d;
                if(fir[d]==-1){ 
                    fir[d]=R;
                    cand[i].push_back({u,d,R});
                    t.push_back(d);
                }else if(fir[d]!=R&&!sec[d]){ 
                    sec[d]=true;
                    cand[i].push_back({u,d,R});
                }
                u=hc[u];
            }
            for(int d:t) fir[d]=-1,sec[d]=false; 
        }
    }
    for(int i=0;i<q;i++){
        long long m=qs[i];
        int u=1;
        while(!e[u].empty()){ 
            int bad=-1;
            for(auto& c:cand[u]){
                if(m%c.d!=c.R){
                    bad=c.u;
                    break;
                }
            }
            if(bad==-1){
                u=bot[u];
            }else{
                int d=e[bad].size();
                int x=(m+D[bad])%d; 
                u=e[bad][x]; 
            }
        }
        cout<<u<<(i==q-1?"":" ");
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}