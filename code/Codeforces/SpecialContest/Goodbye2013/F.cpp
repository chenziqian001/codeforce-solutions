#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int dep[N];
int fa[N][23];

int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    int ans=dep[x]+dep[y];
    for(int i=21;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    for(int i=21;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    x=fa[x][0];
    ans-=dep[x]*2;
    return ans;
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    int p=4;
    int k1=2,k2=3;
    int res=2;
    fa[2][0]=1;
    fa[3][0]=1;
    fa[4][0]=1;
    dep[2]=dep[3]=dep[4]=1;
    while(q--){
        int node;
        cin>>node;
        fa[p+1][0]=fa[p+2][0]=node;
        for(int i=1;i<=21;i++){
            fa[p+1][i]=fa[fa[p+1][i-1]][i-1];
            fa[p+2][i]=fa[fa[p+2][i-1]][i-1];
        }
        dep[p+1]=dep[p+2]=dep[node]+1;
        p+=2;
        int l1=lca(p,k1),l2=lca(p,k2);
        if(l1>l2 && l1>res) res=l1,k2=p;
        if(l2>=l1 && l2>res) res=l2,k1=p;
        cout<<res<<'\n';

    }
    //system("pause");

}