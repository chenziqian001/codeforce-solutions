#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
int dfn[N];
int p[N];
int f[N];
int cnt;
int n;
void dfs(int node,int fa){
    p[node]=fa;
    for(int next:g[node]){
        if(next==fa) continue;
        dfs(next,node);
    }
    dfn[++cnt]=node;
}

int solve(int k){
    int res=0;
    for(int i=1;i<=n;i++) f[i]=1;

    for(int i=1;i<=n;i++){
        int u=dfn[i];
        int v=p[u];
        if(v && f[u]!=-1 && f[v]!=-1){
            if(f[u]+f[v]>=k){
                res++;
                f[v]=-1;
            }
            else{
                f[v]=max(f[v],f[u]+1);
            }
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cnt=0;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);

    int m=sqrt(n);
    cout<<n<<'\n';
    for(int i=2;i<=n;i++){
        if(i<=m) cout<<solve(i)<<'\n';
        else{
            int res=solve(i);
            int l=i,r=n;
            int pos=i;
            while(l<=r){
                int mid=(l+r)/2;
                if(solve(mid)!=res){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                    pos=mid;
                }
            }
            for(int st=i;st<=pos;st++){
                cout<<res<<'\n';
            }
            i=pos;
        }
    }
    //system("pause");
}