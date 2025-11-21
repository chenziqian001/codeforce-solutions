#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
int cnt[N];
int dp[N][25];
int sum,l,r;


int calc(int st,int ed){
    while(l<st) sum-=(--cnt[a[l++]]);
    while(l>st) sum+=cnt[a[--l]]++;
    while(r<ed) sum+=cnt[a[++r]]++;
    while(r>ed) sum-=(--cnt[a[r--]]);
    return sum;
}


void cdq(int lay,int L,int R,int optl,int optr){
    int mid=(L+R)/2;
    int from=max(1LL,optl);
    int to=min(mid,optr);

    int mn=1e18;
    int opt;
    for(int i=from;i<=to;i++){
        if(mn>dp[i-1][lay-1]+calc(i,mid)){
            mn=dp[i-1][lay-1]+calc(i,mid);
            opt=i;
        }
    }
    dp[mid][lay]=mn;

    if(L==R) return;

    cdq(lay,L,mid,optl,opt);
    cdq(lay,mid+1,R,opt,optr);

}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    sum=l=r=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=1e18;
        }
    }
    dp[0][0]=0;

    for(int lay=1;lay<=k;lay++){
        memset(cnt,0,sizeof(int)*(N+1));
        l = 1; r = 0; sum = 0;
        cdq(lay,1,n,1,n);
    }


    cout<<dp[n][k]<<'\n';
    //system("pause");
}