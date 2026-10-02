#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,a[N],b[N],val[N];
int fa[N],sz[N],edge[N],mx1[N],mx2[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

void solve(){
    cin>>n;

    int tot=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        val[++tot]=a[i];
        val[++tot]=b[i];
    }
    sort(val+1,val+tot+1);
    tot=unique(val+1,val+tot+1)-val-1;
    for(int i=1;i<=tot;i++){
        fa[i]=i;
        sz[i]=1;
        edge[i]=0;
        mx1[i]=val[i];
        mx2[i]=0;
    }

    for(int i=1;i<=n;i++){
        int u=lower_bound(val+1,val+tot+1,a[i])-val;
        int v=lower_bound(val+1,val+tot+1,b[i])-val;
        int fu=find(u),fv=find(v);
        if(fu!=fv){
            fa[fu]=fv;
            sz[fv]+=sz[fu];
            edge[fv]+=edge[fu]+1;
            if(mx1[fu]>mx1[fv]){
                mx2[fv]=max(mx1[fv],mx2[fu]);
                mx1[fv]=mx1[fu];
            }
            else mx2[fv]=max(mx2[fv],mx1[fu]);
        }
        else edge[fv]++;
    }

    int res=0;
    for(int i=1;i<=tot;i++){
        if(find(i)==i){
            if(edge[i]>sz[i]){
                cout<<-1<<'\n';
                return;
            }
            if(edge[i]==sz[i]) res=max(res,mx1[i]);
            else res=max(res,mx2[i]);
        }
    }
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}