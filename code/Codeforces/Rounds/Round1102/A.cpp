#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    bool ok=true;
    sort(a.rbegin(),a.rend());
    for(int i=2;i<n;i++){
        if(a[i]!=(a[i-2]%a[i-1])) ok=false;
    }
    if(ok){
        cout<<a[0]<<" "<<a[1]<<'\n';
    }
    else cout<<-1<<'\n';


    

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