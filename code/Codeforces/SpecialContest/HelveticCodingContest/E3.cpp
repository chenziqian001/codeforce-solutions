#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;

vector<vector<int>> mul(vector<vector<int>> a,vector<vector<int>> b){
    int ra=a.size();
    int ca=a[0].size();
    int cb=b[0].size();
    vector<vector<int>> res(ra,vector<int>(cb));
    for(int i=0;i<ra;i++){
        for(int j=0;j<ca;j++){
            if(a[i][j]==0) continue;
            for(int k=0;k<cb;k++){
                res[i][k]=(res[i][k]+a[i][j]*b[j][k]%mod+mod)%mod;
            }
        }
    }
    return res;
}

vector<vector<int>> qp(vector<vector<int>> m,vector<vector<int>> f0,int n){
    vector<vector<int>> res=f0;
    while(n){
        if(n&1) res=mul(res,m);
        m=mul(m,m);
        n>>=1;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n;
    cin>>m>>n;
    vector<int> s(m);
    vector<int> l(m);
    vector<int> sum(m);
    for(int i=0;i<m;i++) cin>>s[i];
    for(int i=0;i<m;i++) cin>>l[i];
    vector<vector<int>> B(m,vector<int>(2));
    vector<vector<int>> C(2,vector<int>(m));
    for(int i=0;i<m;i++){
        B[i][0]=s[i]+l[i];
        B[i][1]=((-l[i])%mod+mod)%mod;
    }
    for(int j=0;j<m;j++){
        C[0][j]=s[j]+l[j];
        C[1][j]=l[j];
    }
    vector<vector<int>> init(2,vector<int>(2,0));
    init[0][0]=1;
    init[1][1]=1;
   
    vector<vector<int>> ma=qp(mul(C,B),init,n-1);
    
    
    
    vector<vector<int>> f0(1,vector<int>(m));
    f0[0][0]=1;
    B=mul(f0,B);
    ma=mul(B,ma);
    ma=mul(ma,C);
    
    int res=0;
    for(int i=0;i<m;i++){
        res=(res+ma[0][i])%mod;
    }
    cout<<res<<'\n';
    //system("pause");
}


