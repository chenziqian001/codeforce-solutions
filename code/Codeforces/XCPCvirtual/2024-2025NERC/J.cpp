#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=9e18;
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++) cin>>a[i].second;
    for(int i=0;i<n;i++) cin>>a[i].first;
    sort(a.begin(),a.end());
    vector<int> pa(n+1);
    for(int i=1;i<=n;i++) pa[i]=pa[i-1]+a[i-1].second;
    vector<int> last(n+1,inf);
    for(int i=n-1;i>=0;i--) last[i]=min(last[i+1],a[i].first)-a[i].second;
    vector<int> tv(m);
    vector<int> ptv(m+1);
    for(int i=0;i<m;i++){
        cin>>tv[i];
        ptv[i+1]=ptv[i]+tv[i];
    } 
    
    while(q--){
        int t;
        cin>>t;
        int x=upper_bound(a.begin(),a.end(),make_pair(t,inf))-a.begin();
        int l1=pa[x];
        int r1=min(t,last[x]);
        auto it=upper_bound(ptv.begin(),ptv.end(),r1-l1);
        it--;
        cout<<it-ptv.begin()<<" "; 
    }
    cout<<'\n';
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}

