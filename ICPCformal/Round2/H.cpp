#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }




}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}