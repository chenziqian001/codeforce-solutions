#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2e18;


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> pre(n+1,0);
    for(int i=0;i<n;i++) pre[i+1]=pre[i]+(s[i]=='0');
    
    int res=-1;
    for(int i=0;i<=n;i++){
        int l=pre[i];
        int r=(n-i)-(pre[n]-pre[i]);
        if(l*2>=i && r*2>=(n-i)){
            if(res==-1 || abs(n-2*i)<abs(n-2*res)) res=i;
        }
    }
    cout<<res<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}