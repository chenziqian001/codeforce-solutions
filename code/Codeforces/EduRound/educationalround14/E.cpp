#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;


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



vector<vector<int>> qp(vector<vector<int>> m,int n,vector<vector<int>> f0){
    vector<vector<int>> res=f0;
    
    while(n){
        if(n&1) res=mul(m,res);
        m=mul(m,m);
        n>>=1;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> m(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(__builtin_popcountll(a[i]^a[j])%3==0){
                m[i][j]=1;
                m[j][i]=1;
            }
        }
    }
    vector<vector<int>> f0(n,vector<int>(1,1));
    vector<vector<int>> res=qp(m,k-1,f0);
    int ans=0;
    for(int i=0;i<n;i++) ans=(ans+res[i][0])%mod;
    cout<<ans<<'\n';
}