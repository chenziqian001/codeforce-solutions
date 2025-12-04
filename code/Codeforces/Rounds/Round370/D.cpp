#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int N=5e5+10;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,k,t;
    cin>>a>>b>>k>>t;

    vector<int> f(N);
    vector<int> s(N);

    int n=2*k*t;
    f[n]=1;
    for(int i=1;i<=2*t;i++){
        s[0]=f[0];
        for(int j=1;j<=2*n+k;j++){
            s[j]=(s[j-1]+f[j])%mod;
        }
        for(int j=0;j<=k;j++){
            f[j]=s[j+k];
        }
        for(int j=k+1;j<=2*n;j++){
            f[j]=(s[j+k]-s[j-k-1]+mod)%mod;
        }
    }

    int res=0;
    for(int i=n-a+b+1;i<=2*n;i++){
        res=(res+f[i])%mod;
    }

    cout<<res<<'\n';
    //system("pause");

}