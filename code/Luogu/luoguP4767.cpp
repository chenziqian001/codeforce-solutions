#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
const int N=4000;
const int M=310;
int n;
int w[N][N];
int f[N];
int g[N];
int a[N];


void init(){
    for(int i=1;i<N;i++){
        w[i][i]=0;
    }
    for(int len=2;len<N;len++){
        for(int i=1;i+len-1<N;i++){
            int j=i+len-1;
            w[i][j]=w[i+1][j-1]+a[j]-a[i];
        }
    }
}



void cdq(int l,int r,int optl,int optr){
    if(l>r) return;
    int mid=(l+r)/2;
    int opt=-1;
    int mini=inf;

    for(int k=optl;k<=min(mid-1,optr);k++){
        int val=f[k]+w[k+1][mid];
        if(val<mini){
            opt=k;
            mini=val;
        }
    }
    g[mid]=mini;

    cdq(l,mid-1,optl,opt);
    cdq(mid+1,r,opt,optr);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin>>n>>k;
   
    for(int i=1;i<=n;i++) cin>>a[i];
   
    sort(a+1,a+n+1);
    init(); 
    for(int i=1;i<=n;i++){
        f[i]=w[1][i];
    }

    for(int j=2;j<=k;j++){
        for(int i=1;i<=n;i++) g[i]=inf;
        cdq(j,n,j-1,n);
        swap(g,f);
    }
    cout<<f[n]<<'\n';
    //system("pause");
    return 0;
}
