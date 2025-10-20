#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> deg(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        deg[a[i]]++;
    }
    queue<int> q;

    for(int i=1;i<=n;i++){
        if(deg[i]==0) q.push(i);
    }
    vector<int> sz(n+1,1);
    int res=0; 
    while(!q.empty()){
        int node=q.front();
        q.pop();
        int next=a[node];
        res=max(res,sz[node]);
        sz[next]+=sz[node];
        if(--deg[next]==0){
            q.push(next);
        }
    }
    cout<<res+2<<'\n';
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}