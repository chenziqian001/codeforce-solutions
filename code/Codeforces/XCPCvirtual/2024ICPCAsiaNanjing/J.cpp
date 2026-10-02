#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> have(k+1);
    vector<int> fd(k+1);
    vector<int> now(k+1);
    map<pair<int,int>,int> cnt;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        fd[x]=1;
    }    
    int ans=0;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(fd[u] && fd[v]) ans++;
        else if(fd[u]) have[v]++;
        else if(fd[v]) have[u]++;
        else{
            if(u>v) swap(u,v);
            if(u!=v) cnt[{u,v}]++;
            else have[u]++;
        }
    }
    for(auto &[p,c]:cnt){
        auto &[u,v]=p;
        now[u]=max(now[u],have[u]+have[v]+c);
        now[v]=max(now[v],have[u]+have[v]+c);
    }
    int res=0;
    vector<int> tmp;
    for(int i=1;i<=k;i++){
        if(!fd[i]){
            res=max(res,now[i]);
            tmp.push_back(have[i]);
        } 
    }
    sort(tmp.begin(),tmp.end(),greater<int>());
    int sz=tmp.size();
    if(sz>=2){
        res=max(res,tmp[0]+tmp[1]);
    }
    else if(sz==1) res=max(res,tmp[0]);
    cout<<ans+res<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}