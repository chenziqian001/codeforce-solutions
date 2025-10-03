#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;


vector<int> prime_fac(int x){
    vector<int> res;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) res.push_back(i);
        while(x%i==0) x/=i;
    }
    if(x>1) res.push_back(x);
    return res;
}

int count(int x,int mx){
    vector<int> pf=prime_fac(x);
    int sz=pf.size();
    int res=0;
    for(int s=0;s<(1<<sz);s++){
        int mul=1;
        int cnt=0;
        for(int i=0;i<sz;i++){
            if(s&(1<<i)){
                cnt++;
                mul*=pf[i];
            }
        }
        if(cnt%2==0){
            res+=mx/mul;
        }
        else{
            res-=mx/mul;
        }
    }
    res=(res+mod)%mod;
    return res;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    int res=1;
    for(int i=1;i<n;i++){
        if(a[i-1]%a[i]){
            cout<<0<<'\n';
            return;
        }
        int g=a[i-1]/a[i];
        int mul=count(g,m/a[i])%mod;
        res=(res*mul)%mod;
    }

    cout<<res<<'\n';
    
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
}