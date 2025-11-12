#include<bits/stdc++.h>
using namespace std;
const int N=200;
bitset<N> use[N],base[N],tmp[N];
int dis[N][N];
int n,m;
struct g{
    int x,y,d;
}edge[N];
bool cmp(g a,g b){
    return a.d<b.d;
}
void mul(bitset<N> *a,bitset<N> *b){
    bitset<N> res[N];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]) res[i]|=b[j];
        }
    }
    for(int i=1;i<=n;i++) a[i]=res[i];
}

void qp(bitset<N> *a,int x){
    bitset<N> res[N];
    for(int i=1;i<=n;i++)  res[i][i]=1;
    while(x){
        if(x&1) mul(res,a);
        mul(a,a);
        x>>=1;
    }
    for(int i=1;i<=n;i++) a[i]=res[i];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int res=0x3f3f3f3f;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,d;
        cin>>x>>y>>d;
        edge[i].x=x;
        edge[i].y=y;
        edge[i].d=d;
    }
    sort(edge+1,edge+1+m,cmp);
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        use[i][i]=1;
        dis[i][i]=0;
    }
    int la=0;
    for(int i=1;i<=m;i++){
        int x=edge[i].x,y=edge[i].y,d=edge[i].d;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[j][k]=min(dis[j][k],dis[j][x]+dis[y][k]+1);
            }
        }
        for(int j=1;j<=n;j++) tmp[j]=base[j];
        qp(tmp,d-la);
        mul(use,tmp);
        for(int j=1;j<n;j++){
            if(use[1][j]){
                if(dis[j][n]!=0x3f3f3f3f){
                    res=min(res,d+dis[j][n]);
                }
            }
        }
        la=d;
        base[x][y]=1;
    }

    if(res==0x3f3f3f3f) cout<<"Impossible"<<'\n';
    else cout<<res<<'\n';
    //system("pause");
}