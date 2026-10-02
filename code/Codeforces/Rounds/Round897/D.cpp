#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> b(n+1);
    for(int i=1;i<=n;i++) cin>>b[i];

    if(k==1){
        for(int i=1;i<=n;i++){
            if(b[i]!=i){
                cout<<"NO"<<'\n';
                return;
            }
        }
        cout<<"YES"<<'\n';
        return;
    }

    vector<int> nx(n+1);
    for(int i=1;i<=n;i++){
        if(b[i]==i){
            cout<<"NO"<<'\n';
            return;
        }
        nx[i]=b[i];
    }    
    vector<int> vis(n+1,0);
    vector<int> t(n+1);
    int time=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        int cur=i;
        while(!vis[cur]){
            vis[cur]=1;
            t[cur]=time++;
            int next=nx[cur];
            cur=next;
        }
        int len=time-t[cur];
        if(len!=k && vis[cur]==1){
            cout<<"NO"<<'\n';
            return;
        }
        cur=i;

        while(vis[cur]==1){
            vis[cur]=2;
            int next=nx[cur];
            cur=next;
        }
        
    }
    cout<<"YES"<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    //system("pause");
    return 0;
}