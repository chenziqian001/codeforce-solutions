#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    bool ok=false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==100){
            ok=true;
        }
    }
    if(ok){
        cout<<"Yes"<<'\n';
    }
    else{
        cout<<"No"<<'\n';
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