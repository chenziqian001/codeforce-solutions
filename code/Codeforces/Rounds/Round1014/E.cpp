#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int s=((n-2)*2+(m-2)*2)%mod;
    int w=0;
    int b=0;
    for(int i=0;i<k;i++){
        int x,y,c;
        cin>>x>>y>>c;
        if(((x==1 || x==n)&&(y!=1 && y!=m))||((y==1 || y==m)&&(x!=1 && x!=n))){
            if(c==0) w++;
            else b++;
        }
    }
    int tt=m*n;
    if(w+b==s){
        if(b&1) cout<<0<<'\n';
        else cout<<qp(2,tt-k)<<'\n';
        return;
    }
    cout<<qp(2,tt-k-1)<<'\n';

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}