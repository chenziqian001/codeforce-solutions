#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=114514;
struct node{
    int c,num,val;
    bool operator<(const node o) const{
        return val<o.val;
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> dis(n+1,vector<int>(n+1,inf));
    for(int st=1;st<=n;st++){
        dis[st][st]=0;
        queue<int> q; 
        q.push(st);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:g[u]){
                if(dis[st][v]==inf){
                    dis[st][v]=dis[st][u]+1;
                    q.push(v);
                }
            }
        }
    }
    int w;
    cin>>w;
    vector<node> v(w);
    for(int i=0;i<w;i++) cin>>v[i].c>>v[i].num>>v[i].val; 
    sort(v.begin(),v.end()); 
    int q;
    cin>>q;
    while(q--){
        int gc,r,a;
        cin>>gc>>r>>a;
        auto check=[&](int d)->bool{
            int s=0,cost=0;
            for(int i=0;i<w;i++){
                if(dis[gc][v[i].c]<=d){
                    int take=min(r-s,v[i].num); 
                    s+=take;
                    cost+=take*v[i].val;
                    if(s==r)return cost<=a;
                }
            }
            return false;
        };
        int L=0,R=n;
        int res=n+1;
        while(L<=R){
            int mid=(L+R)/2;
            if(check(mid)){
                res=mid;
                R=mid-1;
            }else{
                L=mid+1;
            }
        }
        cout<<(res==n+1?-1:res)<<'\n';
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}
 




