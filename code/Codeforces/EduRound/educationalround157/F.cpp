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

vector<vector<int>> mul(vector<vector<int>> &a,vector<vector<int>> &b){
    int ra=a.size();
    int ca=a[0].size();
    int cb=b[0].size();
    vector<vector<int>> res(ra,vector<int>(cb));
    for(int i=0;i<ra;i++){
        for(int j=0;j<ca;j++){
            if(a[i][j]==0) continue;
            for(int k=0;k<cb;k++){
                res[i][k]=(res[i][k]+a[i][j]*b[j][k]%mod)%mod;
            }
        }
    }
    return res;
}
vector<vector<int>> mqp(vector<vector<int>> &m,vector<vector<int>> f0,int n){
    vector<vector<int>> res=f0;
    while(n){
        if(n&1) res=mul(m,res);
        m=mul(m,m);
        n>>=1;
    }
    return res;
}

void solve(){
    
    int n,x,k;
    cin>>n>>x>>k;
    int tt=qp(2*k+1,n-1);
    tt=tt*(x+k)%mod;
    if(!x){
        cout<<tt<<'\n';
        return;
    }
    vector<vector<int>> f0(x,vector<int>(1,1));
    vector<vector<int>> m(x,vector<int>(x));
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(abs(i-j)<=k){
                m[i][j]=1;
            }
        }
    }

    vector<vector<int>> bad=mqp(m,f0,n-1);
    for(int i=0;i<x;i++){
        tt=(tt-bad[i][0]+mod)%mod;
    }
    cout<<tt<<'\n';
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