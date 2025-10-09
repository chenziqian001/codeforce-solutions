#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> pre(n+1);
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i];
        if(s[i]=='1') pre[i+1]++;
        else pre[i+1]--;
    }
    sort(pre.begin(),pre.end());
    int res=0;
    for(int i=1;i<=n;i++){
        res+=i*(n-i+1);
    }
    for(int i=0;i<=n;i++){
        res+=pre[i]*(i-(n-i));
    }
    cout<<res/2<<'\n';

}


signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}



