#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        g[i].push_back(i+1);
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
    }
    vector<int> d(n,inf);
    d[0]=1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({1,0});
    while(!q.empty()){
        auto qq=q.top();
        q.pop();
        int dis=qq.first;
        int node=qq.second;
        if(dis>d[node]) continue;
        for(int next:g[node]){
            if(dis+1<d[next]){
                d[next]=dis+1;
                q.push({d[next],next});
            }
        }
    }
    vector<int> suf(n);
    for(int i=0;i<n;i++){
        for(int j:g[i]){
            if(i>j-d[i]-1) continue;
            suf[i+1]++;
            suf[j-d[i]]--; 
        }
    }
    for(int i=0;i<n-1;i++){
        suf[i+1]+=suf[i];
        cout<<(suf[i]==0);
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
