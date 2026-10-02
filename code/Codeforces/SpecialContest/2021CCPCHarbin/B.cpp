#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int res=0;

    for (int val=2;val<=200;val++){
        vector<bool> vis(150,false);
        int tmp=0;
        for(int i=1;i<=n;i++){
            int need=val-a[i];
            if(need<1 || need>100) continue;
            if(vis[need]){
                tmp+=2;
                vis.assign(150,false);
            }
            else{
                vis[a[i]]=true;
            }

        }
        res=max(res,tmp);


    }
    cout<<res<<'\n';




}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}