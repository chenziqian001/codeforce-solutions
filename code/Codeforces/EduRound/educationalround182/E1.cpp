#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> L,R;
    for(int i=0;i<n;i++){
        if(L.empty() || a[i]>L.back()) L.push_back(a[i]);
    }
    for(int i=n-1;i>=0;i--){
        if(R.empty() || a[i]>R.back()) R.push_back(a[i]);
    }
    vector<vector<int>> dpl(n+1,vector<int>((int)L.size()+1));
    vector<vector<int>> dpr(n+2,vector<int>((int)R.size()+1));
    dpl[0][0]=1;
    for(int i=0;i<n;i++){
        for(int x=0;x<L.size();x++){
            dpl[i+1][x]=(dpl[i+1][x]+dpl[i][x])%mod;
            if(a[i]==L[x]) dpl[i+1][x+1]=(dpl[i+1][x+1]+dpl[i][x])%mod;
            if(x>0 && a[i]<=L[x-1]) dpl[i+1][x]=(dpl[i+1][x]+dpl[i][x])%mod;
        }
    }
    dpr[n+1][0]=1;
    for(int i=n;i>=1;i--){
        for(int x=0;x<R.size();x++){
            dpr[i][x]=(dpr[i][x]+dpr[i+1][x])%mod;
            if(a[i-1]==R[x]) dpr[i][x+1]=(dpr[i][x+1]+dpr[i+1][x])%mod;
            if(x>0 && R[x-1]>=a[i-1])  dpr[i][x]=(dpr[i][x]+dpr[i+1][x])%mod;
        }
    }
    int res=0;
    for(int x=0;x<n;x++){
        for(int y=x;y<n;y++){
            if(a[x]==L.back() && a[y]==R.back()){
                int len=max(0LL,y-x-1LL);
                res=(res+dpl[x+1][(int)L.size()]*dpr[y+1][(int)R.size()]%mod*qp(2,len)%mod)%mod;
            }
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
    return 0;
}
