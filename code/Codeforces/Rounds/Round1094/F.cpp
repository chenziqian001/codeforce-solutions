#include<bits/stdc++.h>
using namespace std;
#define int long long

struct DSU{
    vector<int> p,sz;
    DSU(int n){
        p.resize(n+1);
        sz.resize(n+1,1);
        iota(p.begin(),p.end(),0);
    }
    int find(int x){return x==p[x]?x:(p[x]=find(p[x]));}
    bool unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return false;
        if(sz[x]<sz[y])swap(x,y);
        p[y]=x;
        sz[x]+=sz[y];
        return true;
    }
};

struct RollbackDSU{
    vector<int> p,sz;
    vector<pair<int,int>> hist;
    RollbackDSU(int n){
        p.resize(n+1);
        sz.resize(n+1,1);
        iota(p.begin(),p.end(),0);
    }
    int find(int x){
        while(x!=p[x])x=p[x];
        return x;
    }
    bool unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return false;
        if(sz[x]<sz[y])swap(x,y);
        p[y]=x;
        sz[x]+=sz[y];
        hist.push_back({y,x});
        return true;
    }
    int state(){return hist.size();}
    void rollback(int st){
        while(hist.size()>st){
            int y=hist.back().first,x=hist.back().second;
            sz[x]-=sz[y];
            p[y]=y;
            hist.pop_back();
        }
    }
};


void solve(){
       
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}