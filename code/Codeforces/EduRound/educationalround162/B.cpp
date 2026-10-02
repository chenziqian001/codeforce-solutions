#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k;
    cin>>n>>k;
    
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> hp(n+1);

    for(int i=0;i<n;i++){
        int pos;
        cin>>pos;
        hp[abs(pos)]+=a[i];
    }
    int amo=0;
    for(int i=1;i<=n;i++){
        amo+=k;
        amo-=hp[i];
        if(amo<0){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';


    
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    //system("pause");
    return 0;
}