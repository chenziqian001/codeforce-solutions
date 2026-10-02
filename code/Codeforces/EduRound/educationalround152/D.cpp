#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;cin>>n;
    vector<int> a(n),vis(n);
    for(int i=0;i<n;i++)cin>>a[i];

    struct node{int l,r,t;};
    vector<node> p;
    for(int i=0;i<n;i++){
        if(!a[i])continue;
        int j=i,t=1;
        while(j<n && a[j]){
            if(a[j]==2) t=2;
            j++;
        }
        p.push_back({i,j-1,t});
        i=j-1;
    }
    int ans=p.size();
    for(auto s:p) if(s.t==2){
        if(s.l>0 && !a[s.l-1])vis[s.l-1]=1;
        if(s.r<n-1 && !a[s.r+1])vis[s.r+1]=1;
    }
    for(auto s:p) if(s.t==1){
        if(s.l> 0&& !a[s.l-1] && !vis[s.l-1]) vis[s.l-1]=1;
        else if(s.r<n-1 && !a[s.r+1] && !vis[s.r+1]) vis[s.r+1]=1;
    }
    for(int i=0;i<n;i++) if(!a[i] && !vis[i]) ans++;
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    //system("pause");
    return 0;
}