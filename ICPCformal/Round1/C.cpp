#include<bits/stdc++.h>
using namespace  std;

void solve(){
    int m,n;
    cin>>m>>n;
    map<int,vector<int>> mp;
    while(m--){
        int l,r;
        cin>>l>>r;
        mp[l].push_back(r);
    }    
    vector<pair<int,vector<int>>> adj(mp.begin(),mp.end());
    multiset<int> s;
    int res=n;
    for(int i=0;i<adj.size();i++){
        auto& [l,vec]=adj[i];
        for(auto r:vec){
            s.insert(r);
        }
        int nextl=(i+1==(int) adj.size())?n:adj[i+1].first;
        for(int j=l;j<nextl;j++){
            while(!s.empty() && *s.begin()<=j){
                s.erase(s.begin());
            }
            if(s.empty()) break;
            res--;
            s.erase(s.begin());
        }
    }
    cout<<res<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}


