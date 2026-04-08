#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> adj(n);
    for(int i=0;i<n;i++) adj[i]|=(1<<i);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u]|=(1<<v);
        adj[v]|=(1<<u);
    }

    vector<int> dom(1<<n);
    for(int m=0;m<(1<<n);m++){
        for(int i=0;i<n;i++){
            if(m&(1<<i)){
                dom[m]|=(adj[i]);
            }
        }
    }
    vector<int>dp(1<<n,0);
    for(int i=0;i<n;i++)dp[1<<i]=1<<i;
    
    int msk=-1,lst=-1;
    int full=(1<<n)-1;


    for(int mask=1;mask<(1<<n);mask++){
        int s=__builtin_ctz(mask);
        
        if(__builtin_popcount(mask)>1&&(dp[mask]&adj[s])){
            if(dom[mask]==full){
                msk=mask;
                lst=__builtin_ctz(dp[mask]&adj[s]);
                break;
            }
        }
        int ep=dp[mask];
        while(ep){
            int i=__builtin_ctz(ep);
            ep&=ep-1;
            int avail=adj[i]&~mask;
            avail&=~((1<<(s+1))-1); 
            while(avail){
                int j=__builtin_ctz(avail);
                dp[mask|(1<<j)]|=1<<j;
                avail&=avail-1;
            }
        }
    }


    if(msk==-1){
        cout<<"No"<<'\n';
        return;
    }
    vector<int> a(n);
    int cur=msk;
    int curn=lst;
    int s=__builtin_ctz(msk);
    a[curn]=s; 

    while(__builtin_popcount(cur)>1){
        int pre=cur^(1<<curn);
        int cands=dp[pre]&adj[curn];
        int p=__builtin_ctz(cands);
        a[p]=curn; 
        cur=pre;
        curn=p;
    }


    for(int i=0;i<n;i++){
        if(!((msk>>i)&1)){
            a[i]=__builtin_ctz(adj[i]&msk);
        }
    }
    cout<<"Yes"<<'\n';
    for(int i=0;i<n;i++)cout<<a[i]+1<<(i==n-1?"":" ");
    cout<<'\n';
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