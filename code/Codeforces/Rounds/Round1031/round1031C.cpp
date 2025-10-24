#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> p(n+1,vector<int>(m+1));
    vector<string> g(n);
    vector<pair<int,int>> pos;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>g[i];
        for(int j=0;j<m;j++){
            if(g[i][j]=='g'){
                p[i+1][j+1]=1;
                cnt++;
            }
            else if(g[i][j]=='.') pos.push_back({i,j});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            p[i][j]+=p[i][j-1]+p[i-1][j]-p[i-1][j-1];
        }
    }
    auto get=[&](int x1,int y1,int x2,int y2){
        return p[x2][y2]+p[x1-1][y1-1]-p[x2][y1-1]-p[x1-1][y2];
    };
    int mini=cnt;
    for(auto [x,y]:pos){
        int x2=min(n-1,x+k-1);int y2=min(m-1,y+k-1);
        int x1=max(0,x-k+1);int y1=max(0,y-k+1);
        mini=min(mini,get(x1+1,y1+1,x2+1,y2+1));
    }
    cout<<cnt-mini<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}