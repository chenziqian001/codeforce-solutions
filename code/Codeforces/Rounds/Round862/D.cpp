#include<bits/stdc++.h>
using namespace std;
#define int long long 



void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> dis(n+1);
    dis[0]=-1;
    int p=0;
    function<void(int,int,int)> dfs=[&](int node,int fa,int s){
        dis[node]=s;
        if(dis[node]>dis[p]){
            p=node;
        }
        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node,s+1);
        }
    };
    dfs(1,0,0);
    int x=p;
    dis[0]=-1;
    dfs(x,0,0);
    int y=p;
    
    vector<int> dis1(n+1,-1);
    vector<int> dis2(n+1,-1);
    auto get=[&](vector<int> &d,int rt){
        d[rt]=0;
        queue<int> q;
        q.push(rt);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:t[u]){
                if(d[v]!=-1) continue;
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    };
    get(dis1,x);
    get(dis2,y);
    for(int i=1;i<=n;i++){
        dis1[i]=max(dis1[i],dis2[i]);
    }
    vector<int> res(n+2);
    for(int i=1;i<=n;i++){
        res[dis1[i]+1]++;
    }
    int cur=0;
    for(int i=1;i<=n;i++){
        cur+=res[i];
        cout<<min(n,cur+1)<<" ";
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