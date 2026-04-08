#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }


    vector<vector<int>> mx(n + 1), mn(n + 1);
    vector<int> fa(n + 1);


    auto init=[&](){
        for(int i=1;i<=n;i++) fa[i]=i;
    };
    function<int(int)> find=[&](int x)->int{
        return x==fa[x]?x:fa[x]=find(fa[x]);
    };

    init();
    for(int node=1;node<=n;node++){
        for(int next:t[node]){
            if(next<node && find(next)!=find(node)){
                mx[node].push_back(find(next));
                fa[find(next)]=find(node);
            }
        }
    }

    init();
    for(int node=n;node>=1;node--){
        for(int next:t[node]){
            if(next>node && find(next)!=find(node)){
                mn[node].push_back(find(next));
                fa[find(next)]=find(node);
            }
        }
    }

    int res=0;
    int id=0;
    vector<int> st(n + 1), ed(n + 1), szmx(n + 1), szmn(n + 1);
    vector<int> dep(n+200005);

    function<void(int)> dfsmx=[&](int node){
        szmx[node]=1;
        st[node]=++id;
        for(int next:mx[node]){
            dfsmx(next);
            szmx[node]+=szmx[next];
        }
        res+=szmx[node]-1;
        ed[node]=id;
    };
    dfsmx(n);
    function<void(int)> dfsmn=[&](int node){
        szmn[node]=1;
        for(int next:mn[node]){
            dep[next]=dep[node]+1;
            dfsmn(next);
            szmn[node]+=szmn[next];
        }
        res+=szmn[node]-1;
    };

    dep[1]=1;
    dfsmn(1);

    vector<int> bit(n + 1, 0);
    auto add = [&](int u, int k) {
        for(;u<=n;u+=u&-u) bit[u] += k;
    };
    auto query = [&](int u) {
        int res = 0;
        for(;u>0;u-=u&-u) res += bit[u];
        return res;
    };


    function<void(int)> fuck=[&](int node){
        res-=2*(query(ed[node])-query(st[node]-1));
        add(st[node],1);
        for(int next:mn[node]) fuck(next);
        add(st[node],-1);
    };
    fuck(1);
    cout<<res<<'\n';


    int m;
    cin>>m;
    int cur=n;
    for(int i=1;i<=m;i++){
        int u;
        cin>>u;
        cur++;
        dep[cur]=dep[u]+1;
        res+=(cur-1)-dep[u];
        cout<<res<<'\n';
    }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;t=1;

    while(t--) solve();
    //system("pause");
    return 0;
}