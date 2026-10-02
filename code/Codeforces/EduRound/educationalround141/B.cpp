#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int idx=i%2==0?i*n+j:i*n+(n-1-j);
            cout<<(idx%2==0?1+idx/2:n*n-idx/2)<<" ";
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
 