#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int base=0;
    for(int i=0;i<n;i++) base+=(s[i]=='1');
    int res=base;
    for(int i=0;i<n;i++){
        if(s[i]=='0') continue;
        int cnt=0;
        if(i) cnt+=(s[i-1]=='1');
        cnt+=(s[i]=='1');
        if(i+1<n) cnt+=(s[i+1]=='1');
        if(cnt) res=min(res,base-cnt+1);
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