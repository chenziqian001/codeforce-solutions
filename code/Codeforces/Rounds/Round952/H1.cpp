#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int pa[N],sz[N];

int find(int a){
    if(a!=pa[a]){
        pa[a]=find(pa[a]);
    }
    return pa[a];
}
void merge(int a,int b){
    int fa=find(a);
    int fb=find(b);
    if(fa!=fb){
        pa[fa]=fb;
        sz[fb]+=sz[fa];
    }
}


void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        pa[i]=i;
        sz[i]=1;
    }
    vector<string> g(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='.') continue;
            if(i && g[i-1][j]=='#') merge(i*m+j,(i-1)*m+j);
            if(j && g[i][j-1]=='#') merge(i*m+j,i*m+j-1);
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        set<int> val;
        int cur=0;
        for(int j=0;j<m;j++){
            if(g[i][j]=='.') cur++;
            if(g[i][j]=='#') val.insert(find(i*m+j));
            if(i && g[i-1][j]=='#') val.insert(find((i-1)*m+j));
            if(i<n-1 && g[i+1][j]=='#') val.insert(find((i+1)*m+j));
        }
        for(int v:val){
            cur+=sz[v];
        }
        res=max(cur,res);
    }
    for(int j=0;j<m;j++){
        set<int> val;
        int cur=0;
        for(int i=0;i<n;i++){
            if(g[i][j]=='.') cur++;
            if(g[i][j]=='#') val.insert(find(i*m+j));
            if(j && g[i][j-1]=='#') val.insert(find(i*m+j-1));
            if(j<m-1 && g[i][j+1]=='#') val.insert(find(i*m+j+1));
        }
        for(int v:val){
            cur+=sz[v];
        }
        res=max(res,cur);
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