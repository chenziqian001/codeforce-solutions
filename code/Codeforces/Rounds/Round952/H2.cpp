#include<bits/stdc++.h>
using namespace std;
#define int long long
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
    vector<int> epi(n+1);
    vector<int> epj(m+1);
    vector<int> R(n+2);
    vector<int> C(m+2);
    vector<vector<int>> O(n+2,vector<int>(m+2));
    int big=n*m;
    vector<int> u(big,1e9),d(big,-1),l(big,1e9),r(big,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='.'){
                epi[i]++;
                epj[j]++;
            }
            else{
                int root=find(i*m+j);
                u[root]=min(u[root],i);
                d[root]=max(d[root],i);
                l[root]=min(l[root],j);
                r[root]=max(r[root],j);
            }

        }
    }

    for(int i=0;i<big;i++){
        if(find(i)==i && g[i/m][i%m]=='#'){
            int ui=max(0LL,u[i]-1),di=min(n-1,d[i]+1);
            int li=max(0LL,l[i]-1),ri=min(m-1,r[i]+1);
            R[ui]+=sz[i];R[di+1]-=sz[i];
            C[li]+=sz[i];C[ri+1]-=sz[i];
            O[ui][li]+=sz[i];
            O[di+1][li]-=sz[i];
            O[ui][ri+1]-=sz[i];
            O[di+1][ri+1]+=sz[i];
        }
    }
    for(int i=1;i<=n;i++){
        R[i]+=R[i-1];
    }
    for(int j=1;j<=m;j++){
        C[j]+=C[j-1];
    }
   for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int a = 0;
            if (i > 0) a += O[i - 1][j];
            if (j > 0) a += O[i][j - 1];
            if (i > 0 && j > 0) a -= O[i - 1][j - 1];
            O[i][j] += a;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,R[i]+C[j]-O[i][j]+epi[i]+epj[j]-(g[i][j]=='.'));
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}