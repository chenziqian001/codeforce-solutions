#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> f(n+1,vector<int>(k,-inf));
    vector<vector<int>> g(n+2,vector<int>(k,-inf));
    vector<int> p(n+1);
    vector<int> tmp(k);
    f[0][0]=0;
    g[1][0]=0;



    for(int i=1;i<=n;i++){
        priority_queue<pair<int,int>> pq;
        for(int j=1;j<=i;j++){
            pq.emplace(g[j][0]+a[j][i],j);
            p[j]=0;
        }
        for(int rk=0;rk<k;rk++){
            auto [val,gp]=pq.top();
            pq.pop();
            f[i][rk]=val;
            p[gp]++;
            pq.push({g[gp][p[gp]]+a[gp][i],gp});
        }


        int l=0,r=0;
        for(int rk=0;rk<k;rk++){
            tmp[rk]=max(f[i-1][l],f[i][r]);
            if(f[i-1][l]>f[i][r]) l++;
            else r++;
        }
        f[i]=tmp;
        g[i+1]=f[i-1];
    }


    for(int i=0;i<k;i++){
        cout<<f[n][i]<<" ";
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