#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int a[N],s[N],st[N][20];
int ch[N*35][2],cnt[N*35],rt[N],tot;

void insert(int pre,int &now,int val){
    now=++tot;
    int u=now,v=pre;
    for(int i=29;i>=0;i--){
        int c=(val>>i)&1;
        ch[u][c^1]=ch[v][c^1];
        ch[u][c]=++tot;
        u=ch[u][c];
        v=ch[v][c];
        cnt[u]=cnt[v]+1;
    }
}

int query(int L,int R,int val){
    int u=R,v=L,res=0;
    for(int i=29;i>=0;i--){
        int c=(val>>i)&1;
        if(cnt[ch[u][c^1]]-cnt[ch[v][c^1]]>0){
            res|=(1<<i);
            u=ch[u][c^1];
            v=ch[v][c^1];
        }else{
            u=ch[u][c];
            v=ch[v][c];
        }
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
        st[i][0]=i;
    }
    for(int j=1;j<=19;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            int x=st[i][j-1];
            int y=st[i+(1<<(j-1))][j-1];
            st[i][j]=a[x]>a[y]?x:y;
        }
    }
    
    tot=0;
    ch[0][0]=ch[0][1]=cnt[0]=0;
    for(int i=1;i<=n+1;i++){
        insert(rt[i-1],rt[i],s[i-1]);
    }
    
    int ans=0;
    auto get=[&](int l,int r){
        int k=__lg(r-l+1);
        int x=st[l][k];
        int y=st[r-(1<<k)+1][k];
        return a[x]>a[y]?x:y;
    };
    
    auto dfs=[&](auto self,int l,int r)->void{
        if(l>r) return;
        int mid=get(l,r);
        if(mid-l<r-mid){
            for(int i=l;i<=mid;i++) ans=max(ans,query(rt[mid],rt[r+1],s[i-1]^a[mid]));
        }else{
            for(int i=mid;i<=r;i++) ans=max(ans,query(rt[l-1],rt[mid],s[i]^a[mid]));
        }
        self(self,l,mid-1);
        self(self,mid+1,r);
    };
    
    dfs(dfs,1,n);
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}