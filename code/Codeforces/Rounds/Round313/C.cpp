#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int N=2e5+10;
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
int inv(int x){
    return qp(x,mod-2);
}
void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}

int C(int n,int m){
    if(n<0 || m<0 || n<m) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<pair<int,int>> pos;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        pos.emplace_back(x,y);
    }
    sort(pos.begin(),pos.end(),[&](pair<int,int> x,pair<int,int> y){
        if(x.second==y.second) return x.first<y.first;
        else return x.second<y.second;
    });
    int res=0;
    int sz=pos.size();
    vector<int> g(sz);
    for(int i=0;i<sz;i++){
        int x=pos[i].first,y=pos[i].second;
        g[i]=C(x+y-2,x-1);
        for(int j=0;j<i;j++){
            int px=pos[j].first,py=pos[j].second;
            int dx=x-px+1,dy=y-py+1;
            g[i]=(g[i]-g[j]*C(dx+dy-2,dx-1)%mod+mod)%mod;
        }
        int dn=n-x+1,dm=m-y+1;
        int cont=g[i]*C(dn+dm-2,dn-1)%mod;
        res=(res+cont)%mod;
    }
    cout<<(C(n+m-2,n-1)-res+mod)%mod<<'\n';
    
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}