#include<bits/stdc++.h>

using namespace std;
#define ll long long
const long long mod=998244353;
const int N=31;
ll dp[N][2][2][2];
ll inv2;
ll fast_pow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res%mod;
}
void solve(){
    ll n,m,A,B;
    cin>>n>>m>>A>>B;
    ll case1=(A+1)%mod;
    case1=case1*((B+1)%mod)%mod;
    ll case2=(A+1)%mod;
    case2=case2*(((B%mod*(B+1)%mod)*inv2%mod)%mod)%mod;
    case2=case2*((fast_pow(2,m)-2+mod)%mod)%mod;
    ll case3=(B+1)%mod;
    case3=case3*(((A%mod*(A+1)%mod)*inv2%mod)%mod)%mod;
    case3=case3*((fast_pow(2,n)-2+mod)%mod)%mod;
    memset(dp,0,sizeof(dp));
    dp[0][0][0][0]=1;
    for(int i=0;i+1<N;i++)
        for(int f1=0;f1<=1;f1++)
            for(int f2=0;f2<=1;f2++)
                for(int fx=0;fx<=1;fx++){
                    ll d=dp[i][f1][f2][fx];
                    if(!d) continue;
                    int j=N-i-2;
                    int curA=(A>>j)&1;
                    int curB=(B>>j)&1;
                    for(int bit_a=0;bit_a<=1;bit_a++)
                        for(int bit_b=0;bit_b<=1;bit_b++)
                            for(int bit_x=0;bit_x<=1;bit_x++){
                                if(f1==0&&bit_a==1&&curA==0) continue;
                                if(f2==0&&bit_b==1&&curB==0) continue;
                                if(fx==0&&bit_x==1&&(bit_a==0||bit_b==0)) continue;
                                int nf1=max(f1,bit_a^curA);
                                int nf2=max(f2,bit_b^curB);
                                int nfx=max(fx,bit_x);
                                ll& d2=dp[i+1][nf1][nf2][nfx];
                                d2=(d2+d)%mod;
                            }
                }
    int choose=0;
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++)            
                choose=(choose+dp[N-1][i][j][1])%mod;
    ll case4=choose;
    case4=case4*((fast_pow(2,n)-2+mod)%mod)%mod;
    case4=case4*((fast_pow(2,m)-2+mod)%mod)%mod;

    ll tcase=case1;
    tcase=(tcase+case2)%mod;
    tcase=(tcase+case3)%mod;
    tcase=(tcase+case4)%mod;
    cout<<tcase<<'\n';
}
int main(){
    inv2=fast_pow(2,mod-2);
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}
