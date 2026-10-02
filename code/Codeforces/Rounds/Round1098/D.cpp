#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;

void solve(){
    int n;
    cin>>n;
    vector<int> hx(n+2),hy(n+2),mn(n+2,inf),mx(n+2,-inf);
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        hx[x]=1;hy[y]=1;
        mn[y]=min(mn[y],x);
        mx[y]=max(mx[y],x);
    }
    for(int i=1;i<=n;i++) hx[i]+=hx[i-1];
    vector<int> smn(n+2,inf),smx(n+2,-inf);
    
    for(int i=n;i>=1;i--){
        smn[i]=min(smn[i+1],mn[i]);
        smx[i]=max(smx[i+1],mx[i]);
    }
    int mxy=0;
    for(int i=n;i>=1;i--) if(hy[i]){mxy=i;break;}
    int ans=0,cmn=inf,cmx=-inf;
    for(int i=1;i<mxy;i++){
        cmn=min(cmn,mn[i]);
        cmx=max(cmx,mx[i]);
        if(!hy[i]) continue;
        int l=max(cmn,smn[i+1]);
        int r=min(cmx,smx[i+1])-1;
        if(l<=r) ans+=hx[r]-hx[l-1];
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}