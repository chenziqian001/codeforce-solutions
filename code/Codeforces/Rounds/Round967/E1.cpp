#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k,p;
    cin>>n>>k>>p;

    vector<vector<int>> f(n+1,vector<int>(k+1)); 
    //f[i][j]，高度为i的子树，子树内的结点被作为终点j次，带左右限制
    vector<vector<int>> g(n+1,vector<int>(k+1));
    //同上，但是无约束

    //对于左右子树，左子树分配l, 右子树分配r,有l+r<=j


    for(int j=0;j<=k;j++){
        f[1][j]=g[1][j]=1;
    }
    for(int i=2;i<=n;i++){
        int pg=0,pf=0;
        for(int j=0;j<=k;j++){
            int val=0;
            for(int l=0;l<=j;l++){
                val=(val+g[i-1][l]*g[i-1][j-l]%p)%p;
            }
            g[i][j]=(pg+val)%p;
            pg=g[i][j];
            int val2=0;
            for(int r=0;2*r<=(j-1);r++){
                val2=(val2+f[i-1][j-r]*g[i-1][r]%p)%p;
            }
            f[i][j]=(pf+2*val2%p)%p;
            pf=f[i][j];
        }
    }

    cout<<f[n][k]<<'\n';
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