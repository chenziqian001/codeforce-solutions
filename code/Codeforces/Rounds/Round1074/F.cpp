#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,q;
    cin>>n>>q;
    int m=(1<<n);
    vector<int> a(m);
    for(int i=0;i<m;i++) cin>>a[i];
    vector<int> pre(m+1);
    for(int i=0;i<m;i++){
        pre[i+1]=pre[i]^a[i];
    }

    while(q--){
        int x,y;
        cin>>x>>y;x--;
        int res=0;
        for(int i=0;i<n;i++){
            int comp=x^1<<i;
            int z=pre[comp+(1<<i)]^pre[comp];
            if(!(y>z || (y==z && x<comp))){
                res+=(1<<i);
            }
            x=min(x,comp);
            y^=z;
        }
        cout<<res<<'\n';
    }
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
