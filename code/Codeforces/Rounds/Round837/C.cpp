#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n-1));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1;j++){
            cin>>a[i][j];
        }
    }

    int f = (a[0][0] == a[1][0]) ? a[0][0] : ((a[0][0] == a[2][0]) ? a[0][0] : a[1][0]);
    cout<<f;
    
    for(int i=0;i<n;i++){
        if(a[i][0] != f){
            for(int j=0;j<n-1;j++){
                cout<<" "<<a[i][j];
            }
            break;
        }
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