#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];

    int pre=b[0];
    for(int i=1;i<n;i++){
        if(b[i]>2*pre-1){
            cout<<"NO"<<'\n';
            return;
        }
        pre=min(pre,b[i]);
    }

    cout<<"YES"<<'\n';



    
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