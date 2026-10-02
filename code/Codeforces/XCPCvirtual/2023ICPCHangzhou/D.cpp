#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    if(n == 2){
        cout<<"1 2 -1 1\n";
        return;
    }
    vector<int> res(2*n+1);
    for(int i=2;i<2*n;i++){
        if(i%2==0) res[i]=2;
        else res[i]=-1;
    }
    res[2*n]=1;
    res[1]=2*n-3;
    for(int i=1;i<=2*n;i++) cout<<res[i]<<" ";
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



