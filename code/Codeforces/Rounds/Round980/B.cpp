#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dis(n+1,inf);
    dis[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        auto [w,u]=pq.top();
        pq.pop();
        if(u>1 && dis[u-1]>dis[u]){
            dis[u-1]=dis[u];
            pq.push({dis[u-1],u-1});
        }
        if(dis[b[u]]>dis[u]+a[u]){
            dis[b[u]]=dis[u]+a[u];
            pq.push({dis[b[u]],b[u]});
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dis[i]==inf) continue;
        ans=max(ans,pre[i]-dis[i]);
    }
    cout<<ans<<'\n';
}


signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}