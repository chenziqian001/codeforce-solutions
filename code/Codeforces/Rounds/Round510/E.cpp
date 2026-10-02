#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
int inv(int x){return qp(x,mod-2);}
struct node{
    int val,x,y;
    bool operator<(const node o)const{return val<o.val;}
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<node>v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            v.push_back({x,i,j});
        }
    }
    int r,c;
    cin>>r>>c;
    sort(v.begin(),v.end());
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int cnt=0,si=0,sj=0,sii=0,sjj=0,sum=0;
    for(int i=0;i<v.size();){
        int ed=i;
        while(ed<v.size()&&v[ed].val==v[i].val)ed++;
        int nsi=0,nsii=0,nsj=0,nsjj=0,nsum=0;
        for(int j=i;j<ed;j++){
            int x=v[j].x,y=v[j].y;
            if(cnt>0){
                int cur=(sum+cnt*x%mod*x%mod-2*x%mod*si%mod+sii+cnt*y%mod*y%mod-2*y%mod*sj%mod+sjj+mod)%mod;
                cur=(cur%mod+mod)%mod;
                dp[x][y]=cur*inv(cnt)%mod;
            }
            nsum=(nsum+dp[x][y])%mod;
            nsi=(nsi+x)%mod;
            nsj=(nsj+y)%mod;
            nsii=(nsii+x*x%mod)%mod;
            nsjj=(nsjj+y*y%mod)%mod;
        }
        cnt+=ed-i;
        si=(si+nsi)%mod;
        sj=(sj+nsj)%mod;
        sii=(sii+nsii)%mod;
        sjj=(sjj+nsjj)%mod;
        sum=(sum+nsum)%mod;
        i=ed;
    }
    cout<<dp[r][c]<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    //system("pause");
    return 0;
}