#include<bits/stdc++.h>
using namespace std;
#define int long long 


void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    if(n>m){
        vector<vector<int>> b(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) b[j][i]=a[i][j];
        }
        swap(n,m);
        a=b;
    }
    int res=1e9;
    if(n>k){
        for(int i=0;i<n;i++){
            int cur=0;
            for(int j=0;j<n;j++){
                int d =0;
                for(int k=0;k<m;k++){
                    if(a[i][k]!=a[j][k]) d++;
                }
                cur+=min(d,m-d);
            }
            res=min(res,cur);
        }
    }
    else{
        for(int s=0;s<(1<<k);s++){
            int cur=0;
            for(int j=0;j<m;j++){
                int d=0;
                for(int i=0;i<n;i++){
                    if((s>>i&1)!=a[i][j]) d++;
                }
                cur+=min(d,n-d);
            }
            res=min(res,cur);
        }
    }
    if(res<=k){
        cout<<res<<'\n';
    }
    else cout<<-1<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //system("pause");
}
