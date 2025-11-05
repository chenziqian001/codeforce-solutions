#include<bits/stdc++.h>
using namespace std;
const int sz=20;
vector<int> d;
vector<vector<int>> t;
vector<vector<int>> pa;
void prec(int node,int fa){
    d[node]=d[fa]+1;
    pa[node][0]=fa;
    for(int i=1;i<=sz;i++){
        pa[node][i]=pa[pa[node][i-1]][i-1];
    }
    for(int next:t[node]){
        if(next==fa) continue;
        prec(next,node);
    }
}
int lca(int x,int y){
    if(d[x]<d[y]){
        swap(x,y);
    }
    for(int i=sz;i>=0;i--){
        if(d[x]-(1<<i)>=d[y]){
            x=pa[x][i];
        }
    }
    for(int i=sz;i>=0;i--){
        if(pa[x][i]!=pa[y][i]){
            x=pa[x][i];
            y=pa[y][i];
        }
    }
    return x==y?x:pa[x][0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    t.resize(n+1);
    d.resize(n+1);
    pa.resize(n+1,vector<int>(sz+1));
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    prec(1,0);
    int q;
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        vector<int> b(k);
        for(int i=0;i<k;i++) cin>>b[i];
        sort(b.begin(),b.end(),[&](int x,int y){
            return d[x]>d[y];
        });
        vector<int> vis(k);
        int cnt=0;
        for(int i=0;i<k;i++){
            if(lca(b[i],b[0])==b[i]){
                vis[i]=1;
                cnt++;
            }
        }
        if(cnt==k){
            cout<<"YES"<<'\n';
            continue;
        }
        int pin=0;
        while(pin<k && vis[pin]) pin++;
        for(int i=pin;i<k;i++){
            if(vis[i]) continue;
            if(lca(b[pin],b[i])==b[i]){
                vis[i]=1;
            }
        }
        int res=1;
        for(int x:vis) res&=x;
        res&=(d[lca(b[0],b[pin])]<=d[b.back()]);
        if(res){
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<'\n';

    }
    //system("pause");

}