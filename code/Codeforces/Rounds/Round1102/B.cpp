#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;



void solve(){
    int n;
    cin>>n;
    int p[12]={0,1,2,3,4,5,6,7,8,9,22,11};
    int a = p[n%12];
    if(a>n){
        cout<<-1<<'\n';
    }
    else {
        cout<<a<<" "<<n-a<<'\n';
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