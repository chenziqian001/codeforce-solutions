#include<bits/stdc++.h>
using namespace std;
#define int long long


const int inf=2e18;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    vector<int> c=a;
    sort(c.begin(),c.end());
    for(int i=n-1;i>=0;i--){
        if(c[i]>b[i]){
            cout<<-1<<'\n';
            return;
        }
    }

    vector<bool> vis(n,false);
    int res=0;
    for(int i=0;i<n;i++){
        int p=-1;
        for(int j=0;j<n;j++){
            if(!vis[j] && a[j]<=b[i]){
                p=j;
                break;
            }
        }
        vis[p]=1;
        for(int j=0;j<p;j++){
            if(!vis[j]) res++;
        }
    }
    cout<<res<<'\n';
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