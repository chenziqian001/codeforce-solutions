#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define int long long


int get(int x){
    int res=0;
    for(int i=0;i<=30;i++){
        if(x>>i&1) res++;
    }
    return res;
}

void solve(){
    int n,k;
    cin>>n>>k;
    if(n==1){
        cout<<k<<'\n';
        return;
    }

    vector<int> a(n);
    for(int i=29;i>=0;i--){
        if(k>>i&1){
            a[0]=((1<<i)-1);
            
            break;
        }
    }
    a[1]=k-a[0];
    for(int x:a){
        cout<<x<<" ";
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