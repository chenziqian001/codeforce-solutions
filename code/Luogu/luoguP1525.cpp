#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
};
bool cmp(node a,node b){
    return a.z>b.z;
}
int find(int x,vector<int>& fa){
    if(fa[x]!=x) fa[x]=find(fa[x],fa);
    return fa[x];
}

void merge(int x,int y,vector<int>& fa){
    x=find(x,fa);
    y=find(y,fa);
    fa[x]=y;
}
bool check(int x,int y,vector<int>& fa){
    return find(x,fa)==find(y,fa);
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<node> edge(m);
    for(int i=0;i<m;i++){
        cin>>edge[i].x>>edge[i].y>>edge[i].z;
    }
    sort(edge.begin(),edge.end(),cmp);
    
    vector<int> fa(n+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    vector<int> opos(n+1);
    for(int i=0;i<m;i++){
        if(check(edge[i].x,edge[i].y,fa)){
            cout<<edge[i].z<<'\n';
            return;
        }
        else{
            if(!opos[edge[i].x]) opos[edge[i].x]=edge[i].y;
            else merge(opos[edge[i].x],edge[i].y,fa);
            if(!opos[edge[i].y]) opos[edge[i].y]=edge[i].x;
            else merge(opos[edge[i].y],edge[i].x,fa);
        }
    }
    cout<<0<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}