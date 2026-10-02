#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n;
    cin>>n;
    if(n==2){
        cout<<"Bob"<<'\n';
        return;
    }
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    int tg=n-1;
    int st=0;
    for(int i=0;i<n;i++){
        if(t[i].size()==1){
            st++;
        }
    }
    if((tg-st)%2==1){
        cout<<"Alice"<<'\n';
    }
    else cout<<"Bob"<<'\n';

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
 
 