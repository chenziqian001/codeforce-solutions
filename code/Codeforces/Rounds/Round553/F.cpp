#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
const int mod=1e9+7;
int n,k,c,x,a[105];
struct Mat{
    int m[105][105];
    Mat(){memset(m,0,sizeof(m));}
    Mat operator*(const Mat&o)const{
        Mat r;
        for(int i=0;i<=c;i++)
            for(int p=0;p<=c;p++)
                for(int j=0;j<=c;j++)
                    r.m[i][j]=(r.m[i][j]+m[i][p]*o.m[p][j])%mod;
        return r;
    }
};
int qp(int a,int b){
    int r=1;
    while(b){
        if(b&1)r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}


void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!a[i]) c++;
    }
    for(int i=1;i<=c;i++){
        if(!a[i]) x++;
    }
    Mat m,r;
    int S=(n-1)*n/2%mod,iS=qp(S,mod-2);
    for(int i=0;i<=c;i++){
        int up=(c-i)*(c-i)%mod;
        int down=i*(n-2*c+i)%mod;
        int stay=(S-up-down)%mod;
        stay=(stay%mod+mod)%mod;
        if(i<c)m.m[i][i+1]=up*iS%mod;
        if(i>0)m.m[i][i-1]=down*iS%mod;
        m.m[i][i]=stay*iS%mod;
        r.m[i][i]=1;
    }
    while(k){
        if(k&1) r=r*m;
        m=m*m;
        k>>=1;
    }
    cout<<r.m[x][c]<<'\n';
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