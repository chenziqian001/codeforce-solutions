#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

void solve(){
    int n,p;
    cin>>n>>p;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(p==1){
        cout<<n%2<<'\n';
        return;
    }
    sort(a.rbegin(),a.rend());
    int d=0,res=0,lst=a[0];
    for(int i=0;i<n;i++){
        int g=lst-a[i];
        res=res*qp(p,g)%mod;
        int tmp=d;
        while(g && tmp<=n && tmp>0){
            tmp*=p;
            g--;
        }
        if(tmp>n) tmp=n+1;
        d=tmp;

        if(d>0){
            d--;
            res=(res-1+mod)%mod;
        }
        else{
            d++;
            res=(res+1)%mod;
        }
        lst=a[i];
    }
    cout<<(res*qp(p,lst)%mod)<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    //system("pause");
    return 0;
}

