#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,m,k,T;
    cin>>n>>m>>k>>T;
    vector<vector<int>> v(n,vector<int>(k+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            cin>>v[i][j];
        }
    }
    vector<int> time(m);
    vector<vector<int>> l(m,vector<int>(n));
    vector<vector<int>> to(m,vector<int>(m));
    






}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}