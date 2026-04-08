#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+10;
int fa[N],sz[N],imp[N],val[N];

void make(int node,int x){
    fa[node]=node,sz[node]=1,imp[node]=1,val[node]=x;
}

int find(int node){
    if(fa[node]!=node){
        fa[node]=find(fa[node]);
    }
    return fa[node];
}

void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(sz[x]<sz[y]) swap(x,y);
    fa[y]=x;
    sz[x]+=sz[y];
    imp[x]=min(imp[x],imp[y]);
}

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> a(n,vector<int>(m));
    vector<vector<int>> id(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            id[i][j]=i*m+j;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            make(id[i][j],a[i][j]);
            for(int d=0;d<4;d++){
                int nx=i+dx[d];
                int ny=j+dy[d];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(a[nx][ny]<a[i][j]){
                    imp[id[i][j]]=0;
                }
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int d=0;d<4;d++){
                int nx=i+dx[d];
                int ny=j+dy[d];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(a[nx][ny]==a[i][j]){
                    merge(id[nx][ny],id[i][j]);
                }
            }
        }
    }


    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(find(id[i][j])==id[i][j]){
                res+=imp[id[i][j]];
            }
        }
    }
    cout<<res<<'\n';


    int q;
    cin>>q;
    int nd=n*m;


    while(q--){
        int r,c,x;
        cin>>r>>c>>x;
        r--,c--;

        x=a[r][c]-x;
        set<int> s;
        int mini=2e18;
        for(int d=0;d<4;d++){
            int nx=r+dx[d];
            int ny=c+dy[d];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            s.insert(find(id[nx][ny]));
            mini=min(mini,a[nx][ny]);
        }

        s.insert(find(id[r][c]));
        for(auto fk:s){
            res-=imp[fk];
        }
        for(auto fk:s){
            if(val[fk]>x){
                imp[fk]=0;
            }
        }
        make(nd,x);
        imp[nd]=mini<x?0:1;


        
        for(auto fk:s){
            if(val[fk]==x){
                merge(fk,nd);
            }
        }
        a[r][c]=x;
        id[r][c]=nd++;
        
        s.clear();
        for(int d=0;d<4;d++){
            int nx=r+dx[d];
            int ny=c+dy[d];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            s.insert(find(id[nx][ny]));
        }
        s.insert(find(id[r][c]));

        for(auto fk:s){
            res+=imp[fk];
        }

        cout<<res<<'\n';
    }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}

