#include<bits/stdc++.h>
using namespace std;

int find(int x,vector<int> &fa){
    if(x!=fa[x]) fa[x]=find(fa[x],fa);
    return fa[x];
}

void merge(int x,int y,vector<int> &fa){
    int fx=find(x,fa);
    int fy=find(y,fa);
    fa[fx]=fy;
}
bool check(int x,int y,vector<int> &fa){
    return find(x,fa)==find(y,fa);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> fa(2*m+1);
    for(int i=1;i<=2*m;i++) fa[i]=i;
    vector<vector<int>> g(n+1);
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int node;
            cin>>node;
            g[node].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            merge(g[i][0],g[i][1],fa);
            merge(g[i][0]+m,g[i][1]+m,fa);
        }
        else{
            merge(g[i][0],g[i][1]+m,fa);
            merge(g[i][0]+m,g[i][1],fa);
        }
    }
    for(int i=1;i<=m;i++){
        if(check(i,i+m,fa)){
            cout<<"NO"<<'\n';
            return 0;
        }
    }
    cout<<"YES"<<'\n';
    return 0;
}