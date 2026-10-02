#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> g(1003,vector<int>(1003,-1));
    
    int dx[4]={1,0,1,1};
    int dy[4]={0,1,1,-1};
    int s[2]={0};
    int tp=0;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x][y]=tp;
        for(int j=0;j<4;j++){
            int l1=0,l2=0;
            int nx=x+dx[j],ny=y+dy[j];
            while(nx>=1&&nx<=1000&&ny>=1&&ny<=1000&&g[nx][ny]==tp) l1++,nx+=dx[j],ny+=dy[j];
            nx=x-dx[j],ny=y-dy[j];
            while(nx>=1&&nx<=1000&&ny>=1&&ny<=1000&&g[nx][ny]==tp) l2++,nx-=dx[j],ny-=dy[j];
            s[tp]-=max(0LL,l1-5+1);
            s[tp]-=max(0LL,l2-5+1);
            s[tp]+=max(0LL,l1+l2+1-5+1);
        }
        cout<<s[tp]<<" ";
        tp^=1;
    }
    cout<<'\n';

    

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}