#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;



void solve(){
    int n,q;
    cin>>n>>q;
    int N=(1LL<<n);
    vector<int> limi(2*N,N);
    vector<int> L(N+1),R(N+1,N-1);
    vector<bool> req(N+1,false);

    while(q--){
        int u,x;
        cin>>u>>x;
        limi[u]=min(limi[u],x);
        int d=31-__builtin_clz((unsigned) u);

        int width=(N>>d);
        int lef=(u-(1<<d))*width;
        int rig=lef+width-1;
        req[x]=true;
        L[x]=max(L[x],lef);
        R[x]=min(R[x],rig);

    }
    vector<vector<int>> pos(N+1);
    for(int u=1;u<2*N;u++){
        if(u>1){
            limi[u]=min(limi[u],limi[u/2]);
        }
        if(u>=N){
            pos[limi[u]].push_back(u-N);
        }
    }
    int res=1;
    int ok=0;
    for(int x=N;x>=1;x--){
        ok+=(int) pos[x].size();
        int c;
        if(req[x]){
            if(L[x]>R[x]){
                cout<<0<<'\n';
                return;
            }
            const auto &p=pos[x];
            c=upper_bound(p.begin(),p.end(),R[x])-lower_bound(p.begin(),p.end(),L[x]);
        }
        else{
            c=ok-(N-x);
        }
        if(c<=0){
            cout<<0<<'\n';
            return;
        }
        res=res*c%mod;
    }
    cout<<res<<'\n';
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