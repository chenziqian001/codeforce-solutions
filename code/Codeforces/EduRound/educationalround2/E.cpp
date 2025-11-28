#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    

    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    vector<int> sz(n);
    function<void(int,int)> sel=[&](int node,int fa){
        if(fa!=-1){
            t[node].erase(find(t[node].begin(),t[node].end(),fa));
        }
        sz[node]=1;
        for(int i=0;i<t[node].size();i++){
            if(t[node][i]==fa) continue;
            sel(t[node][i],node);
            sz[node]+=sz[t[node][i]];
            if(sz[t[node][i]]>sz[t[node][0]]){
                swap(t[node][i],t[node][0]);
            }

        }
    };
    sel(0,-1);

    vector<long long> res(n);
    vector<long long> cnt(n+1);
    vector<long long> feq(n+1);
    feq[0]=n*(n+1)/2;
    long long mx=0;


    auto addv=[&](int val,int ti){
        feq[cnt[val]]-=val;
        cnt[val]+=ti;
        mx=max(mx,cnt[val]);
        feq[cnt[val]]+=val;
        while(!feq[mx]) mx--;
    };

    function<void(int,int)> upd=[&](int node,int ti){
        addv(a[node],ti);
        for(int next:t[node]){
            upd(next,ti);
        }
    };

    function<void(int)> dfs=[&](int node){
        for(int next:t[node]){
            if(next==t[node][0]) continue;
            dfs(next);
            upd(next,-1LL);
        }

        if(!t[node].empty()){
            dfs(t[node][0]);
            for(int next:t[node]){
                if(next==t[node][0]) continue;
                upd(next,1LL); 
            }
        }

        addv(a[node],1LL);
        res[node]=feq[mx];
    };

    dfs(0);
    upd(0,-1);

    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }

    cout<<'\n';
    //system("pause");
    return 0;
}