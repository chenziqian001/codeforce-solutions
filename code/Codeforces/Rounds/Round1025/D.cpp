#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+1;

void solve(){
    int n,m,l;
    cin>>n>>m>>l;
    vector<int> a(l);
    for(int i=0;i<l;i++) cin>>a[i];
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> dis(n,vector<int>(2,inf));
    dis[0][0]=0;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        auto [node,p]=q.front();
        q.pop();
        int np=1-p;
        for(int next:g[node]){
            if(dis[next][np]==inf){
                dis[next][np]=dis[node][p]+1;
                q.push({next,np});
            }
        }
    }
    int sum=0;
    int min_odd=inf;
    for(int i=0;i<l;i++){
        sum+=a[i];
        if(a[i]%2==1){
            min_odd=min(min_odd,a[i]);
        }
    }
    bool ok=(min_odd!=inf);
    string res="";
    int sp=sum%2;
    for(int i=0;i<n;i++){
        bool valid=false;
        for(int j=0;j<2;j++){
            if(sp==j){
                if(sum>=dis[i][j]) valid=true;
            }
            else{
                if(ok){
                    if(sum-min_odd>=dis[i][j]) valid=true;
                }
            }
        }
        res+=valid?'1':'0';
    }
    cout<<res<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}