#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=200007;
int fac[N],ifac[N];

int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
int C(int n,int m){
    return fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}
int inv(int x){
    return qp(x,mod-2);
}
void init(){
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--){
        ifac[i]=ifac[i+1]*(i+1)%mod;
    }
}

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int L=lower_bound(a.begin(),a.end(),x)-a.begin();
    int R=upper_bound(a.begin(),a.end(),x)-a.begin();
    cout<<L<<" "<<R<<'\n';
    int res=0;
    if(L<R){
        res=C(n-R+L,L);
        for(int i=L+1;i<R;i++){
            res=(res+C(n,i))%mod;
        }
        int l=0,r=n-1;
        while(l<r && a[l]<x && a[r]>x){
            if(a[l]+a[r]<2*x){
                l++;
                continue;
            }
            if(a[l]+a[r]>2*x){
                r--;
                continue;
            }
            int p=l,q=r;
            while(l<n && a[l]==a[p]) l++;
            while(r>=0 && a[r]==a[q]) r--;
            int A=p,B=l,D=n-q-1,E=n-r-1;


            res=(res+C(B+E,B))%mod;
            res=(res+C(A+D,A))%mod;
            res=(res-C(A+E,A)+mod)%mod;
            res=(res-C(B+D,B)+mod)%mod;

            //res=(res+C(B+E,B)-C(A+E,A)-C(B+D,B)+C(A+D,A)+2LL*mod)%mod; 

        }


    }

    cout<<res<<'\n';
}



signed main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    init();
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
}