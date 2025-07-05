#include<bits/stdc++.h>
using namespace std;




void solve(){
    int n,m;
    cin>>n>>m;
 
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    bool flag=false;
    int N=m*n+1;
    int col[N]{};
    int bc[N]{};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            col[a[i][j]]=1;
            if(i+1<n){
                if(a[i][j]==a[i+1][j]){
                    bc[a[i][j]]=1;
                    flag=true;
                }
            }
            if(j+1<m){
                if(a[i][j]==a[i][j+1]){
                    bc[a[i][j]]=1;
                    flag=true;
                }
            }
        }
    }
    int tc=0;
    for(int i=0;i<N;i++){
        tc+=col[i];
    }
    int tb=0;
    for(int i=0;i<N;i++){
        tb+=bc[i];
    }
    cout<<tc+tb-1-(flag?1:0)<<'\n';

    

   
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}