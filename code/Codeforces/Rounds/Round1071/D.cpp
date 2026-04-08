#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<bool> vis(1<<n,false);
    int num=(1<<n)-1;
    while(num){
        vis[num]=true;
        int base=num;
        cout<<num<<" ";
        int m=n-__builtin_popcount(num);
        int st=(1<<m)-1;
        for(int i=1;i<=st;i++){
            int x=base+(i<<(__builtin_popcount(num)));
            if(vis[x]) continue;
            cout<<x<<" ";
            vis[x]=true;
        }
        num>>=1;
    }
    for(int i=0;i<(1<<n);i++){
        if(vis[i]) continue;
        cout<<i<<" ";
    }
    cout<<'\n';
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


