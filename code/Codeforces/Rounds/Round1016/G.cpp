#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,cnt,ans;
int a[N],son[N*30][2],pos[N*30];

void add(int x,int id){
    int d=0;
    for(int i=30;i>=0;i--){
        int bit=(x>>i)&1;
        if(!son[d][bit]) son[d][bit]=++cnt;
        d=son[d][bit];
        pos[d]=max(pos[d],id);
    }
}

int get(int x){
    int d=0,res=0;
    for(int i=30;i>=0;i--){
        int xbit=(x>>i)&1;
        int mbit=(m>>i)&1;
        if(mbit==0){
            if(son[d][xbit^1]) res=max(res,pos[son[d][xbit^1]]);
            if(!son[d][xbit]) return res;
            d=son[d][xbit];
        }
        else{
            if(!son[d][xbit^1]) return res;
            d=son[d][xbit^1];
        }
    }
    res=max(res,pos[d]);
    return res;
}
void solve(){
    for(int i=0;i<=cnt;i++) son[i][0]=son[i][1]=pos[i]=0;
    cnt=0;
    ans=1e9;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        add(a[i],i);
        if(get(a[i])) ans=min(ans,i-get(a[i])+1);
    }
    if(ans==1e9){
        cout<<-1<<'\n';
        return;
    }
    else{
        cout<<ans<<'\n';
    }
}


 
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}