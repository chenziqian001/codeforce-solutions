#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dep[N];
int sz[N];
int fa[N][21];
vector<int> t[N];

void dfs(int node,int pa){
    fa[node][0]=pa;
    dep[node]=dep[pa]+1;
    sz[node]=1;
    for(int i=1;i<21;i++){
        if(fa[node][i-1] != 0)
            fa[node][i] = fa[fa[node][i-1]][i-1];
        else
            fa[node][i] = 0;
    }

    for(int next:t[node]){
        if(next==pa) continue;
        dfs(next,node);
        sz[node]+=sz[next];
    }
}
int cnt;
int get(int a,int b){
    if(dep[a]<dep[b]){
        swap(a,b);
    }

    int x=a,y=b;

    int diff=dep[x]-dep[y];
    for(int i=20;i>=0;i--){
        if((diff & (1<<i))){  
            x = fa[x][i];
        }
    }
    
    if(x==y){
        if(diff%2==0){
            int len=diff/2;
        
            int ban2=a;
            for(int i=20;i>=0;i--){
                if((len-1)&(1<<i)){
                    ban2=fa[ban2][i];                    
                }
            }
            return sz[fa[ban2][0]]-sz[ban2];
        }
        else{
            return 0;
        }
    }
    
    for(int i=20;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
   
    int anc=fa[x][0];
  
    int dis=-dep[anc]*2+dep[a]+dep[b];
    if(dis%2==1) return 0;
    else{
        int len=dis/2-1;
        int ban1=a;
        for(int i=20;i>=0;i--){
            if(len&(1<<i)){
                ban1=fa[ban1][i];                    
            }
        }
        int mid=fa[ban1][0];
        if(dep[anc]-dep[a]==dep[anc]-dep[b]){
            int ban2=b;
            for(int i=20;i>=0;i--){
                if(len&(1<<i)){
                    ban2=fa[ban2][i];                    
                }
            }
            return sz[1]-sz[ban1]-sz[ban2];
        }
        else{
            return sz[mid]-sz[ban1];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    memset(fa, 0, sizeof (fa));  
    memset(dep, 0, sizeof(dep));
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        t[v].push_back(u);
        t[u].push_back(v);
    }
    dfs(1,0);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(u==v){
            cout<<n<<'\n';
            continue;
        }
        cout<<get(u,v)<<'\n';
    }
    //system("pause");
}