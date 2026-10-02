#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;



void solve(){
    int n,k;
    cin>>n>>k;
    string s,z;
    cin>>s>>z;

    int ca=0,cb=0,cc=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') ca++;
        if(z[i]=='1') cb++;
        if(s[i]!=z[i]) cc++;
    }
    int pw=(1LL<<k);
    int nc=(pw-(k%2==0?1:-1))/3;
    int na=(pw+1-nc)/2;
    int res=na*ca*(n-ca)+na*cb*(n-cb)+nc*cc*(n-cc);
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