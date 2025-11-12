#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> dis(n,vector<int>(m,-1));
    dis[0][0]=0;
    queue<pair<int,int>> q;
    q.emplace(0,0);


    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();

        if(y<m-1 && a[(x+1)%n][y+1]!=1 && dis[(x+1)%n][y+1]==-1){
            dis[(x+1)%n][y+1]=dis[x][y]+1;
            q.emplace((x+1)%n,y+1);
        }

        if(a[(x + 1) % n][y] == 0 && a[(x+2)%n][y]!=1 && dis[(x+2)%n][y]==-1){
            dis[(x+2)%n][y]=dis[x][y]+1;
            q.emplace((x+2)%n,y);
        }

    }
    int ans=-1;
    for(int i=0;i<n;i++){
        int res=dis[i][m-1];
        if(res==-1) continue;
        if(res%n!=(i+1)%n){
            res+=(i+1-res%n+n)%n;
        }
        if(ans==-1 || res<ans){
            ans=res;
        }
    }

    cout<<ans<<'\n';
};


    




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}
