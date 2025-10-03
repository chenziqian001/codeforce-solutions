#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;


vector<vector<int>> multi(const vector<vector<int>> &a,const vector<vector<int>> &b){
    int n=a.size();
    int m=a[0].size();
    int cn=b[0].size();
    vector<vector<int>> res(n,vector<int>(cn));
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            if(a[i][k]==0) continue;
            for(int j=0;j<cn;j++){
                res[i][j]=(res[i][j]+a[i][k]*b[k][j]%mod)%mod;
            }
        }
    }
    return res;
}
vector<vector<int>> matrix_pow(vector<vector<int>> a,int n,const vector<vector<int>> &f0){
    vector<vector<int>> res=f0;
    while(n){
        if(n&1){
            res=multi(res,a);
        }
        a=multi(a,a);      
        n>>=1;
    }
    return res;
}


signed main(){
    int n,m;
    cin>>n>>m;
    if(n<m){
        cout<<1<<'\n';
        return 0;
    }
    vector<vector<int>> init(m,vector<int>(m));
    init[0][0]=1;
    init[0][m-1]=1;
    for(int i=1;i<m;i++){
        init[i][i-1]=1;
    }
    vector<vector<int>> f0(m,vector<int>(1));
    for(int i=0;i<m;i++) f0[i][0]=1;
    vector<vector<int>> res=matrix_pow(init,n,f0);
    cout<<res[0][0]<<'\n';
    system("pause");
    return 0;
}




