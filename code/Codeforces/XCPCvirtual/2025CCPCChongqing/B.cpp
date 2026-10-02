#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;



struct Mat {
    int r, c;
    vector<vector<int>> m;
    Mat(int r, int c): r(r), c(c) {
        m.assign(r, vector<int>(c, 0));
    }
    Mat operator*(const Mat& o) const {
        Mat res(r, o.c);
        for(int i=0;i<r;i++){
            for(int k=0;k<c;k++){
                if(!m[i][k]) continue;
                for(int j=0;j<o.c;j++){
                    res.m[i][j] = (res.m[i][j] + m[i][k] * o.m[k][j]) %mod;
                }
            }
        }
        return res;
    }
};


Mat qp(Mat a,int b){
    Mat res(a.r,a.r);
    for(int i=0;i<a.r;i++) res.m[i][i]=1;
    while(b){
        if(b&1) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> t(k-1);
    int T=1;
    for(int i=0;i<k-1;i++){
        cin>>t[i];
        T=max(T,t[i]);
    }
    
    vector<int> dp(T+1);
    int s=0;
    for(int i=0;i<T;i++){
        int cur=1;
        for(int j=0;j<k-1;j++){
            if(i>=t[j]){
                cur=(cur+1)%mod;
                for(int m=i-t[j];m<=i-1;m++){
                    cur=(cur+dp[m])%mod;
                }
            }
        }
        dp[i]=cur;
        s=(s+dp[i])%mod;
        if(i==n-1){
            cout<<s<<'\n';
            return;
        }
    }

    int S=T+2;
    Mat M(S,S);

    vector<int> C(T+1);
    for(int x=1;x<=T;x++){
        for(int j=0;j<k-1;j++){
            if(t[j]>=x) C[x]++;
        }
    }
    M.m[0][0] = 1; 
    for(int j=1;j<=T;j++){
        M.m[0][j] = C[j]; 
        M.m[1][j] = C[j];
    }
    M.m[0][S-1] = k;
    M.m[1][S-1] = k;

    for(int r=2;r<=T;r++){
        M.m[r][r-1]=1;
    }
    M.m[S-1][S-1]=1;
    Mat V0(S,1);
    V0.m[0][0]=s;
    for(int i=1;i<=T;i++) V0.m[i][0]=dp[T-i];
    V0.m[S-1][0]=1;
    Mat Vn=qp(M,n-T)*V0;
    cout<<Vn.m[0][0]<<'\n';
    return;
    
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}