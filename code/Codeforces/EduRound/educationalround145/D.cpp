#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=4e18;
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> pre(n+1),suf(n+2);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i-1]=='1');
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+(s[i-1]=='0');
    int res=inf;
    int cd=1e12+1,cs=1e12;
    for(int i=0;i<=n;i++) res=min(res,(pre[i]+suf[i+1])*cd);
    for(int i=0;i<n-1;i++){
        if(s[i]=='1' && s[i+1]=='0') res=min(res,(pre[i]+suf[i+3])*cd+cs);
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
 
