#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    vector<vector<int>> b(n+1,vector<int>(n+1));
    vector<vector<int>> c(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            b[i][j]=a[i][j]*i;
            c[i][j]=a[i][j]*j;
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            c[i][j]+=c[i-1][j]+c[i][j-1]-c[i-1][j-1];
        }
    }
    auto fuck=[&](auto &v,int x1,int y1,int x2,int y2){
        return v[x2][y2]-v[x2][y1-1]-v[x1-1][y2]+v[x1-1][y1-1];
    };
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int aa=fuck(a,x1,y1,x2,y2);
        int bb=fuck(b,x1,y1,x2,y2);
        int cc=fuck(c,x1,y1,x2,y2);
        int res=(y2-y1+1)*bb+cc+(x1*y1-x1*y2-x1-y1+1)*aa;
        cout<<res<<" ";
    }
    cout<<'\n';

}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
