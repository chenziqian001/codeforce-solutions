#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    vector<int> deg(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        t[u].push_back(v);
        t[v].push_back(u);
        deg[u]++;deg[v]++;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(deg[i]==1) cnt++;
    }
    int res=cnt*(n-cnt);
    vector<int> d(n);
    int c=0;
    for(int i=0;i<n;i++){
        if(t[i].size()>1){
            for(int j:t[i]){
                d[i]+=(t[j].size()>1);
            }
            c+=(d[i]==deg[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(deg[i]>1 && d[i]!=deg[i]){
            res+=c*(d[i]-1);
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
    return 0;
}
