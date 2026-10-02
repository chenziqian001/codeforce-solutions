#include<bits/stdc++.h>
using namespace std;
#define int long long


const int inf=2e18;
void solve(){
    int n,k;
    cin>>n>>k;
    int res=0;

    for(int i=0;i<27;i++){
        int x=(1<<i);
        int num=min(n/x,k);
        res+=num;
        n-=num*x;
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