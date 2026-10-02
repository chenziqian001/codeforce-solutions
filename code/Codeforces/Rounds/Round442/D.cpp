#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> g(n);
    for(int i=0;i<n;i++) cin>>g[i];
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a--,b--,c--,d--;
    
    
    vector<vector<int>> dis(n,vector<int>(m,-1));
    dis[a][b]=0;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    queue<pair<int,int>> q;
    q.emplace(a,b);
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        if(x==c && y==d)break;
        for(int i=0;i<4;i++){
            for(int j=1;j<=k;j++){
                int nx = j*dx[i]+x;
                int ny= j*dy[i]+y;
                if(nx<0||nx>=n||ny<0||ny>=m||g[nx][ny]=='#')break;
                if(dis[nx][ny]!=-1 && dis[nx][ny]<dis[x][y]+1)break;
                if(dis[nx][ny]==-1){
                    dis[nx][ny]=dis[x][y]+1;
                    q.push({nx,ny});
                }
            }

        }
    }


    cout<<dis[c][d]<<'\n';
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