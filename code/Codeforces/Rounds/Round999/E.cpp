#include<bits/stdc++.h>
using namespace std;
#define in long long
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int sz=(1LL<<m);
    vector<int> val(sz);
    for(int i=0;i<sz;i++){
        int res=(1LL<<30)-1LL;
        for(int j=0;j<m;j++){
            if(i&(1<<j)) res&=b[j];
        }
        val[i]=res;
    }
    vector<int> suff;
    for(int i=0;i<n;i++){
        vector<int> g(m+1);
        for(int s=0;s<(1<<m);s++){
            int c=__builtin_popcount(s);
            g[c]=max(g[c],a[i]-(a[i]&val[s]));
        }
        for(int j=1;j<=m;j++){
            suff.push_back(g[j]-g[j-1]);
        }
    }
    sort(suff.rbegin(),suff.rend());
    long long res=accumulate(a.begin(),a.end(),0LL);
    for(int i=0;i<suff.size() && i<k;i++){
        res-=suff[i];
    }
    cout<<res<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    
    return 0;
}