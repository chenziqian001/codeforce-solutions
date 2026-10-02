#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;

int qp(int a,int b){
    int r=1;
    while(b){
        if(b&1)r=r*a%M;
        a=a*a%M;
        b>>=1;
    }
    return r;
}

void solve(){
    int k,pa,pb;
    cin>>k>>pa>>pb;
    int Pa=pa*qp(pa+pb,M-2)%M;int Pb=pb*qp(pa+pb,M-2)%M;
    int p=pa*qp(pb,M-2)%M;
    int f[1005][1005];
    for(int i=k;i>=1;i--){
        for(int j=k;j>=0;j--){
            if(i+j>=k) f[i][j]=(i+j+p)%M;
            else f[i][j]=(Pa*f[i+1][j]%M+Pb*f[i][j+i]%M)%M;
        }
    }
    cout<<f[1][0]<<'\n';
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
