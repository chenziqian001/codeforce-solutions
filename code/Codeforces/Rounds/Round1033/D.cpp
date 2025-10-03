#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=1e5+10;
int inv[N];


void solve(){
    int a,b,k;
    cin>>a>>b>>k;
    int n=k*(a-1)+1;
    int ans=k;
    for(int i=1;i<=a;i++) ans=ans*((n-i+1)%mod)%mod*inv[i]%mod;
    ans=(ans*(b-1)%mod+1)%mod;
    n%=mod;
    cout<<n<<" "<<ans<<'\n';

}

signed main(){
    inv[1]=1;
    for(int i=2;i<=100000;i++){
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    }
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}