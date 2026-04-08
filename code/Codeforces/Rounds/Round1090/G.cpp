#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=676767677;



void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> cnt(m+1);
    vector<int> s(m+1);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
        cnt[b[i]]++;
    }

    for(int i=1;i<=m;i++){
        s[i]=s[i-1]+cnt[i-1];
    }


    int res=1;
    for(int i=0;i<n;i++){
        if(b[i]==0) continue;
        int nx=1e9;
        int t=b[i];
        if(i>0) nx=min(nx,b[i-1]);
        if(i+1<n) nx=min(nx,b[i+1]);
        if(nx>=t){
            cout<<0<<'\n';
            return;
        }

        if(nx==t-1){
            res=res*s[t]%mod;
        }
        else{
            res=res*cnt[t-1]%mod;
        }
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
