#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y,mod;


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
vector<vector<int>> qp(vector<vector<int>> &m,int n,vector<vector<int>> &f0){
    vector<vector<int>> res=f0;
    while(n){
        if(n&1) res=mul(m,res);
        m=mul(m,m);
        n>>=1;
    }
    return res;
} 

int f(int s0,int c,int t){
    vector<vector<int>> m={{3,1},{0,1}};
    vector<vector<int>> f0={{s0},{c}};
    return qp(m,t,f0)[0][0];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>x>>y>>mod;
    vector<int> a(n);
    int s0=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s0=(s0+a[i])%mod;
    }
    if(n==1) {
        cout<<s0<<'\n';
        return 0;
    }
    vector<vector<int>> m={{1,1},{1,0}};
    vector<vector<int>> f0={{a[n-1]},{a[n-2]}};
    int big=qp(m,x,f0)[0][0];
    int sx=f(s0,-a[0]-a[n-1],x);
    cout<<(f(sx,-a[0]-big,y)+mod)%mod<<'\n'; 
}