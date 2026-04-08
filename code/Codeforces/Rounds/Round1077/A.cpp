#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> res(n+1);
    res[n]=n;
    int l=1,h=n-1;
    bool ok=true;
    for(int i=n-1;i>=1;i--){
        if(ok){
            res[i]=l++;
        }
        else{
            res[i]=h--;
        }
        ok=!ok;
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
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

