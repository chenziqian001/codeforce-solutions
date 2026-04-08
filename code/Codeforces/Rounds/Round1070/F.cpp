#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=2e5+10;
int fac[N];int ifac[N];
int spf[N],w[N];
int c[7][N]; 
vector<int> act[7];

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
void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;    
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;

    for(int i=2;i<N;i++) spf[i]=i;
    for(int i=2;i*i<N;i++){
        if(spf[i]==i){
            for(int j=i*i;j<N;j+=i){
                spf[j]=i;
            }
        }
    }
    for(int i=2;i<N;i++){
        int tmp=i,cnt=0;
        while(tmp>1){
            int d=spf[tmp];
            cnt++;
            while(tmp%d==0) tmp/=d;
        }
        w[i]=cnt;
    }


}//初始化阶乘
int C(int n,int m) {return fac[n]*ifac[m]%mod*ifac[n-m]%mod;}//组合数


void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=6;i++) act[i].clear();
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        vector<int> p;
        while(v>1){
            int d=spf[v];
            p.push_back(d);
            while(v%d==0) v/=d;
        }
        int sz=p.size();
        for(int s=0;s<(1<<sz);s++){
            int mul=1;
            for(int j=0;j<sz;j++){
                if(s&(1<<j)) mul*=p[j];
            }
            if(!c[sz][mul]){
                act[sz].push_back(mul);
            }
            c[sz][mul]++;
        }
    }

    int res=0;
    for(int x=0;x<=6;x++){
        for(int y=x;y<=6;y++){
            int G[7]={0},F[7]={0};
            int sx=act[x].size()<act[y].size()?x:y;
            for(int mul:act[sx]){
                if(!c[x][mul] || !c[y][mul]) continue;
                int c1=c[x][mul],c2=c[y][mul],s=w[mul];
                if(x==y) G[s]=(G[s]+c1*(c1-1)/2)%mod;
                else G[s]=(G[s]+c1*c2)%mod;
            }
            for(int z=6;z>=0;z--){
                F[z]=G[z];
                for(int i=z+1;i<=6;i++){
                    F[z]=(F[z]-C(i,z)*F[i]%mod+mod)%mod;
                }
                if(F[z])res=(res+F[z]%mod*qp(x+y-z,k)%mod)%mod;
            }
        }

    }

    cout<<res<<'\n';
    for(int x=0;x<=6;x++) for(int mul:act[x]) c[x][mul]=0;
    
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    init();
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}