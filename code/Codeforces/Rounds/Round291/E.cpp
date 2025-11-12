#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int mx=100;


vector<vector<int>> mul(vector<vector<int>> a,vector<vector<int>> b){
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

vector<vector<int>> qp(vector<vector<int>> m,vector<vector<int>> f0,int n){
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
    int n,x;
    cin>>n>>x;
    vector<vector<int>> m(mx+1,vector<int>(mx+1));
    vector<int> cnt(mx+1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=0;i<mx;i++) m[0][i]=cnt[i+1];
    m[0][mx]=1;
    for(int i=1;i<mx;i++) m[i][i-1]=1;m[mx][mx]=1;
    vector<vector<int>> f0(mx+1,vector<int>(1));
    f0[0][0]=1;
    f0[mx][0]=1;
    vector<vector<int>> ans=qp(m,f0,x);
    cout<<ans[0][0]<<'\n';
    //system("pause");
} 