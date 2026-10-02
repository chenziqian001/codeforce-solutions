#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k,m;
    cin>>n>>k>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++) cin>>b[i];
    if((n-m)%(k-1)!=0){
        cout<<"NO"<<'\n';
        return;
    }
    int need=(k-1)/2;
    for(int i=0;i<m;i++){
        int l=b[i]-1-i;
        int r=n-b[i]-(m-1-i);
        if(l>=need&&r>=need){
            cout<<"YES"<<'\n';
            return;
        }
    }
    cout<<"NO"<<'\n';
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