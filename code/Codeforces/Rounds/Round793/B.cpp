#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> tmp;

    for(int i=0;i<n;i++){
        if(a[i]!=i){
            tmp.push_back(a[i]);
        }
    }


    int res=0;
    
    for(int i=0;i<=30;i++){
        bool ok=true;
        for(int x:tmp){
            if(~x>>i&1){
                ok=false;
                break;
            }
        }    
        if(ok) res|=(1<<i);
    }

    cout<<res<<'\n';
    
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

