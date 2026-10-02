#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=200005;
int a[N],ch[N*30][2],L[N*30],R[N*30],tt=1;

void insert(int x,int idx){
    int u=1;
    for(int i=29;i>=0;i--){
        int c=(x>>i)&1;
        if(!ch[u][c]){
            ch[u][c]=++tt;
            L[tt]=idx;
        }
        R[ch[u][c]]=idx;
        u=ch[u][c];
    }
}

int query(int u,int x,int bit){
    if(bit<0) return 0;
    int c=(x>>bit)&1;
    if(ch[u][c]) return query(ch[u][c],x,bit-1);
    return query(ch[u][c^1],x,bit-1)+(1ll<<bit);
}

int dfs(int u,int bit){
    if(bit<0) return 0;
    if(ch[u][0] && ch[u][1]){
        int sz0=R[ch[u][0]]-L[ch[u][0]]+1;
        int sz1=R[ch[u][1]]-L[ch[u][1]]+1;

        int res=1ll<<60;
        if(sz0 <= sz1){
            for(int i=L[ch[u][0]];i<=R[ch[u][0]];i++) res=min(res,query(ch[u][1],a[i],bit-1)+(1ll<<bit));
        }else{
            for(int i=L[ch[u][1]];i<=R[ch[u][1]];i++) res=min(res,query(ch[u][0],a[i],bit-1)+(1ll<<bit));
        }
        return dfs(ch[u][0],bit-1)+dfs(ch[u][1],bit-1)+res;
    }
    if(ch[u][0])return dfs(ch[u][0],bit-1);
    if(ch[u][1])return dfs(ch[u][1],bit-1);
    return 0;
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++) insert(a[i],i);
    cout<<dfs(1,29)<<'\n';
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