#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> v(n/2+1);
    vector<bool> vis(n+1,false);

    for(int i=0;i<n;i++){
        int mn=a[i],mx=a[i];
        int j=i;
        for(;j<n;j++){
            if(vis[a[j]]) break;
            vis[a[j]]=true;
            mn=min(mn,a[j]);
            mx=max(mx,a[j]);
            int l=j-i+1;
            if(mx-mn+1==l && l<=n/2) v[l].push_back(mn);
        }
        for(int k=i;k<j;k++) vis[a[k]]=false;
    }

    vector<bool> has(n+1,false);
    for(int l=n/2;l>=1;l--){
        for(int x:v[l]) has[x]=true;
        bool ok=false;
        for(int x:v[l]){
            if(x+l<=n && has[x+l]){
                ok=true;
                break;
            }
        }
        for(int x:v[l]) has[x]=false;
        if(ok){
            cout<<l<<'\n';
            return;
        }
    }
    cout<<0<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}