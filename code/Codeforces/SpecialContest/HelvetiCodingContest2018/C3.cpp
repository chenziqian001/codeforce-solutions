#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,p;
    cin>>n>>k>>p;

    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=(a[i-1]+x)%p;
    }
    vector<vector<int>> f(n+1,vector<int>(k+1,inf));
    vector<int> g(k+1);
    f[0][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            int opt=g[j-1];
            int cost=(a[i]-a[opt]+p)%p;

            if(f[opt][j-1]!=inf){
                f[i][j]=min(f[i][j],f[opt][j-1]+cost);
            }
        }
        for(int j=0;j<=k;j++){
            if(f[i][j]<f[g[j]][j]){
                g[j]=i;
            }
        }
    }
    cout<<f[n][k]<<'\n';
    //system("pause");
    return 0;
}

