#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,k;
    cin>>n>>k;


    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> b(n+1);
    for(int i=1;i<=n;i++) cin>>b[i];
    vector<int> posa(n+1);
    for(int i=1;i<=n;i++){
        posa[a[i]]=i;
    }

    vector<int> vis(n+1,-1);
    for(int i=1;i<=n;i++){
        if(b[i]==-1) continue;
        if(vis[b[i]]!=-1){
            cout<<"NO"<<'\n';
            return;
        }
        vis[b[i]]=1;
        int ps=posa[b[i]];
        if(ps==i) continue;
        else if(ps<i){
            int l=max(k,ps);
            int r=min(i,n-k+1);
            if(l<i  || r>ps){
                cout<<"NO"<<'\n';
                return;
            }
        }
        else{
            int l=max(k,i);
            int r=min(ps,n-k+1);
            if(l<ps || r>i){
                cout<<"NO"<<'\n';
                return;
            }
        }
    }
    cout<<"YES"<<'\n';
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

