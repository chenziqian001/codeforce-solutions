#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1e5+10;



int qpow(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    } 
    return res;
}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>> divisors(n+1);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            divisors[j].push_back(i);
        }
    }

    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> b(n+1);
    for(int i=0;i<=n;i++) b[i]=i;
    sort(b.begin()+1,b.end(),[&](int x,int y){
        return a[x]>a[y];
    });
    int remain=n-1;
    int res=0;
    vector<bool> banned(n+1,false);
    for(int i=1;i<=n;i++){
        for(int d:divisors[b[i]]){
            if(!banned[d]){
                banned[d]=true;
                res=(res+a[b[i]]*qpow(2,remain)%mod)%mod;
                remain--;
            }

        }
       
    }

    cout<<res<<'\n';

    return 0;
}