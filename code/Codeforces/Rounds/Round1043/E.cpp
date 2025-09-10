#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    vector<int> pa(n+1),pb(m+1);
    for(int i=1;i<=n;i++){
        pa[i]=pa[i-1]+a[i-1];
    }
    for(int i=1;i<=m;i++){
        pb[i]=pb[i-1]+b[i-1];
    }
    vector<pair<int,int>> ans(n+m+1);
    int l=0,r=0;
    for(int i=1;i<ans.size();i++){
        if(l<n && r<m){
            if(a[l]<b[r]){
                r++;
            }
            else{
                l++;
            }
        }
        else if(l==n){
            r++;
        }
        else if(r==m){
            l++;
        }
        ans[i]={l,r};
    }

    while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        auto pp=ans[z];
        int l=pp.first,r=pp.second;
        long long res=0;
        if(x<l){
            res=pa[x]+pb[z-x];
        }
        else if(y<r){
            res=pb[y]+pa[z-y];

        }
        else{
            res=pa[l]+pb[r];
        }
        cout<<res<<'\n';
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}