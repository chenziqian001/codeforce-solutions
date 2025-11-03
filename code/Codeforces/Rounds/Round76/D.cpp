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
                res[i][k]=(res[i][k]+a[i][j]*b[j][k])%mod;
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

int f(int n){
    if(n==0) return 0;
    if(n==1) return 4;
    vector<vector<int>> m(17,vector<int>(17));
    vector<vector<int>> f0(17,vector<int>(1));
    f0[16][0]=4;
    //0123 白黑红黄

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==j || i+j==3) continue;
            for(int k=0;k<4;k++){
                if(j!=k && j+k!=3 && (j!=0 || i+k!=3)){
                    m[i*4+j][j*4+k]=1;
                    m[16][j*4+k]++;
                }
            }
            f0[i*4+j][0]=1;
            f0[16][0]++;
        }
    }
    m[16][16]=1;
    return qp(m,f0,n-2)[16][0];
}


int solve(int x){
    int inv2=(mod+1)/2;
    return ((f(x)+f((x+1)/2))%mod)*inv2%mod;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l,r;
    cin>>l>>r;
    int res=(solve(r)-solve(l-1)+mod)%mod;  
    cout<<res<<'\n';
    return 0; 
}