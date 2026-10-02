#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
const int N=3e6;


int calc(int p, int c, int tp, int tc, int d) {
    if (p >= inf || c >= inf) return inf;
    int ip = (p < tp) ? 0 : (p >= tp + d ? tp + d : p);
    int ic = (c < tc) ? 0 : (c >= tc + d ? tc + d : c);
    return ip + ic;
}

void solve(){
    int n;
    cin>>n;
    vector<int> p(n+1);
    vector<int> c(n+1);
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    vector<int> pre1(N+2,inf),pre2(N+2,inf),suf1(N+2,inf),suf2(N+2,inf);
    int mini=inf;
    int mp,mc;  
    for(int i=1;i<=n;i++){
        pre1[p[i]]=min(pre1[p[i]],c[i]);
        pre2[c[i]]=min(pre2[c[i]],p[i]);
        suf1[p[i]]=min(suf1[p[i]],c[i]);
        suf2[c[i]]=min(suf2[c[i]],p[i]);
        if(p[i]+c[i] <mini){
            mini=p[i]+c[i];
            mp=p[i];
            mc=c[i];
        }
    }
    
    for(int i=1;i<=N;i++) pre1[i]=min(pre1[i],pre1[i-1]), pre2[i]=min(pre2[i],pre2[i-1]);
    for(int i=N;i>=0;i--) suf1[i]=min(suf1[i],suf1[i+1]), suf2[i]=min(suf2[i],suf2[i+1]);
    
    
    int m;
    cin>>m;
    vector<int> tp(m+1),tc(m+1),d(m+1);
    for(int i=1;i<=m;i++) cin>>tp[i];
    for(int i=1;i<=m;i++) cin>>tc[i];
    for(int i=1;i<=m;i++) cin>>d[i];
    for(int i=1;i<=m;i++){
        int qp = max(0LL, tp[i]-1);
        int qc = max(0LL, tc[i]-1);
        int res = calc(mp, mc, tp[i], tc[i], d[i]);
        res = min({res,
                   calc(0, pre1[min(qp, N)], tp[i], tc[i], d[i]),
                   calc(pre2[min(qc, N)], 0, tp[i], tc[i], d[i]),
                   calc(min(tp[i]+d[i], N), suf1[min(tp[i]+d[i], N)], tp[i], tc[i], d[i]),
                   calc(suf2[min(tc[i]+d[i], N)], min(tc[i]+d[i], N), tp[i], tc[i], d[i])});
        cout<<res<<'\n';
    }


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}