#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=5e5+10;



void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> s(k);
    for(int i=0;i<k;i++){
        cin>>s[i].first>>s[i].second;
        s[i].first--,s[i].second--;
    }
    vector<string> g(n);
    for(int i=0;i<n;i++) cin>>g[i];
    vector<int> bt(n*m);
    for(int i=0;i<k-1;i++) bt[s[i].first*m+s[i].second]=k-i-1;
    vector<int> d(n*m,1e9);
    int st=s[0].first*m+s[0].second;
    d[st]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,st});
    int dr[]={-1,1,0,0},dc[]={0,0,-1,1};
    while(!pq.empty()){
        int cd=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(d[u]<cd) continue;
        int r=u/m,c=u%m;
        for(int i=0;i<4;i++){
            int nr=r+dr[i],nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && g[nr][nc]=='.'){
                int v=nr*m+nc;
                int w=max(cd,bt[v])+1;
                if(w<d[v]){
                    d[v]=w;
                    pq.emplace(w,v);
                }
            }
        }
    }
    unsigned long long res=0;
    for(int i=0;i<n*m;i++){
        if(d[i]!=1e9){
            unsigned long long f=d[i];
            res+=f*f;
        }
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
