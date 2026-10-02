#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> p(n+1),cost(n+1);
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if((a<=n && b<=n)||(a>n && b>n)){
            cout<<"-1\n";
            return;
        }
        if(a<=n){
            p[a]=b-n;
            cost[a]=0;
        }else{
            p[b]=a-n;
            cost[b]=1;
        }
    }

    int ans=0,mn=n+1;
    int u=n+1,v=n+1;
    int cx=0,cy=0;
    for(int i=1;i<=n;i++){
        mn=min(mn,p[i]);
        if(p[i]<u&&p[i]<v){
            if(u<v){
                u=p[i];
                cx+=cost[i];
                cy+=1-cost[i];
            }else{
                v=p[i];
                cx+=1-cost[i];
                cy+=cost[i];
            }
        }else if(p[i]<u){
            u=p[i];
            cx+=cost[i];
            cy+=1-cost[i];
        }else if(p[i]<v){
            v=p[i];
            cx+=1-cost[i];
            cy+=cost[i];
        }else{
            cout<<"-1\n";
            return;
        }
        if(mn==n-i+1){
            ans+=min(cx,cy);
            u=n+1,v=n+1;
            cx=0,cy=0;
        }
    }
    cout<<ans<<"\n";
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
