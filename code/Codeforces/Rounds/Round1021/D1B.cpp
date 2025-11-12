#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=1e6;
int fac[N];int ifac[N];
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}//快速幂
int inv(int x) {return qp(x,mod-2);}//逆元
int C(int n,int m) {return fac[n]*ifac[m]%mod*ifac[n-m]%mod;}//组合数
vector<int> fa;
vector<int> sz;

void init (int n){
    fa.resize(n);
    iota(fa.begin(),fa.end(),0);
    sz.assign(n,1);
}


int find(int x){
    if(x!=fa[x]){
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
void merge(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx==fy) return;
    sz[fx]+=sz[fy];
    fa[fy]=fx;
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    init(n*m);
    vector<int> x(k+1),y(k+1);
    for(int i=0;i<=k;i++){
        cin>>x[i]>>y[i];
        x[i]--,y[i]--;
    }
    vector<int> loop(n*m),e(n*m);
    //for(int i=0;i<=k;i++){
    //    int u=x[i]*m+y[i];
    //    loop[u]=1;
    //    e[u]++;
    //} 
    for(int i=1;i<=k;i++){
        if(abs(x[i]-x[i-1])+abs(y[i]-y[i-1])!=2){
            cout<<0<<'\n';
            return;
        }
        int a,b,c,d;
        if(x[i]==x[i-1]){
            a=x[i];
            b=(y[i]+y[i-1])/2;
            c=a;
            d=b;
        }
        else if(y[i]==y[i-1]){
            a=(x[i]+x[i-1])/2;
            b=y[i];
            c=a;
            d=b;
        }
        else{
            a=x[i-1];
            b=y[i];
            c=x[i];
            d=y[i-1];
        }
        int u=a*m+b;
        int v=c*m+d;
        if(find(u)!=find(v)){
            e[find(u)]+=e[find(v)];
            loop[find(u)]|=loop[find(v)];
            merge(u,v);
        }
        e[find(u)]++;
        if(u==v) loop[find(u)]=1;
    }
    int  res=1;
    for(int i=0;i<n*m;i++){
        if(find(i)!=i) continue;
        int s=sz[i];
        if(e[i]>s){
            res=0;
            break;
        }
        else if(e[i]==s){
            if(!loop[i]) res=(res*2)%mod;
        }
        else res=(res*s)%mod;
    }
    cout<<res<<'\n';





}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}


