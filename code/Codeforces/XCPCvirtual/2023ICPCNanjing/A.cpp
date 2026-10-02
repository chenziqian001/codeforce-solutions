#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> g(n);
    vector<pair<int,int>> s;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        cin>>g[i];
        for(int j=0;j<m;j++){
            if(g[i][j]=='.') s.push_back({i,j});
        }
    }
    int ans=0;
    int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='.'&&!v[i][j]){
                vector<pair<int,int>> c;
                queue<pair<int,int>> q;
                q.push({i,j});
                v[i][j]=1;
                while(!q.empty()){
                    auto [r,y]=q.front();
                    q.pop();
                    c.push_back({r,y});
                    for(int k=0;k<4;k++){
                        int nr=r+dx[k],nc=y+dy[k];
                        if(nr>=0&&nr<n&&nc>=0&&nc<m&&g[nr][nc]=='.'&&!v[nr][nc]){
                            v[nr][nc]=1;
                            q.push({nr,nc});
                        }
                    }
                }
                bool ok=true;
                for(auto [vr,vc]:s){
                    if(vr==i&&vc==j) continue;
                    int dr=vr-i,dc=vc-j;
                    bool sub=true;
                    for(auto [cr,cc]:c){
                        int nr=cr+dr,nc=cc+dc;
                        if(nr<0||nr>=n||nc<0||nc>=m||g[nr][nc]=='O'){
                            sub=false;
                            break;
                        }
                    }
                    if(sub){
                        ok=false;
                        break;
                    }
                }
                if(ok) ans+=c.size();
            }
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}