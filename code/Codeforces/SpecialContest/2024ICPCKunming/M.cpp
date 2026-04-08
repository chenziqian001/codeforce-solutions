#include<bits/stdc++.h>
using namespace std;
 
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    cout<<"YES"<<'\n';

    vector<vector<int>> res(n,vector<int>(m));
    int x=1;
    for(int d=0;d<n+m-1;d++){
        int i=max(0LL,d-m+1);
        int j=min(m-1,d);
        for(;i<n && j>=0;i++,j--){
            res[i][j]=x++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<'\n';
    }


    
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

