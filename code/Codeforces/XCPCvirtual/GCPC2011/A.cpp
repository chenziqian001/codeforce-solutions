#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<"\n";
        return;
    }
    int k=n-1;
    int p=__builtin_popcountll(k);
    if(p>2) cout<<"impossible"<<'\n';
    else if(p==1)cout<<1<<'\n';
    else cout<<(k&-k)+1<<'\n';
   
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}