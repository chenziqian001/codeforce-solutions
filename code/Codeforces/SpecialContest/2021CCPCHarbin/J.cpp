#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int res=0;
    int n,m;
    cin>>n>>m;
    vector<int> r(n);
    vector<int> c(m,1e9);


    vector<vector<int>> g(n,vector<int>(m));
    for(int i=0;i<n;i++){
        int rm=1e9;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            g[i][j]=x;
            rm=min(rm,x);
            c[j]=min(c[j],x);
        }
        r[i]=rm;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==r[i] && g[i][j]==c[j]){
                res++;
            }
        }
    }
    cout<<res<<'\n';

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