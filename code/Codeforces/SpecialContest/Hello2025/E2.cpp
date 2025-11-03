#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;


int find(int x,vector<int> &pa){
    if(x!=pa[x]) pa[x]=find(pa[x],pa);
    return pa[x];
}
bool merge(int x,int y,vector<int> &pa){
    int fx=find(x,pa);
    int fy=find(y,pa);
    if(fx==fy) return false;
    pa[fx]=fy;
    return true;
}
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> edge(m,vector<int>(3));
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        edge[i]={u,v,w};
    }
    sort(edge.begin(),edge.end(),[&](auto a,auto b){
        return a[2]<b[2]; 
    });
    vector<vector<vector<int>>> dis(n,vector<vector<int>>(n,vector<int>(n,inf))); 
    for(int i=0;i<n;i++){
        dis[0][i][i]=0;
    }
    for(auto e:edge){
        int u=e[0],v=e[1];
        dis[0][u][v]=dis[0][v][u]=1;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dis[0][i][j]=min(dis[0][i][j],dis[0][i][k]+dis[0][k][j]);
            }
        }
    }

    int p=1;
    vector<int> val(m+1);
    vector<int> pa(n);
    iota(pa.begin(),pa.end(),0);


    for(auto e:edge){
        int u=e[0],v=e[1],w=e[2];
        if(!merge(u,v,pa)) continue;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dis[p][i][j]=min({dis[p-1][i][j],dis[p-1][i][u]+dis[p-1][v][j],dis[p-1][i][v]+dis[p-1][u][j]});
            }
        }
        val[p++]=w;
    }

    while(q--){
        int u,v,k;
        cin>>u>>v>>k;
        u--,v--;
        int l=0,r=n-1;
        while(r-l>1){
            int mid=(l+r)/2;
            if(dis[mid][u][v]<k){
                r=mid;
            }
            else l=mid;
        }
        cout<<val[r]<<" ";
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