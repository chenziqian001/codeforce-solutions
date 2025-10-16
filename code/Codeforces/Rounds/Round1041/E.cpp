#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> w(n);
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) cin>>c[i];

    vector<vector<int>> t(n);
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    function<void(int,int)> color=[&](int node,int fa){
        if(!c[node]) c[node]=c[fa];
        for(int next:t[node]){
            if(next==fa) continue;
            color(next,node);
        }
    };
    long long res=0;
    vector<set<int>> s(n);

    function<void(int node,int fa)> dfs=[&](int node,int fa){
        vector<int> a;

        for(int next:t[node]){
            if(next==fa) continue;
            dfs(next,node);
            if(s[node].size()<s[next].size()) swap(s[node],s[next]);
            for(int val:s[next]){
                if(s[node].count(val)) a.push_back(val);
                else s[node].insert(val);

            }
        }

        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        
        if(a.size()>1 || (a.size()==1&&c[node]&&a[0]!=c[node])){
            res+=w[node];
        }
        
        if(c[node]){
            s[node].insert(c[node]);
        }
        else if(!a.empty()) c[node]=a[0];
        else if(!s[node].empty()) c[node]=*s[node].begin();
        if(c[node]){
            for(int next:t[node]){
                if(next==fa) continue;
                if(!c[next]){
                    color(next,node);
                }
            }
        }
    };
    dfs(0,-1);
    for(int i=0;i<n;i++){
        if(!c[i]) c[i]=1;
    }
    cout<<res<<'\n';
    for(int i=0;i<n;i++){
        cout<<c[i]<<" ";
    }
    cout<<'\n';


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}