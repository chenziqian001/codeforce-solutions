#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;


struct node{
    int s,w,b;
};
void solve(){
    int x,y,p,q;
    cin>>x>>y>>p>>q;
    vector<vector<vector<int>>> f(x+1,vector<vector<int>>(y+1,vector<int>(2,-1)));
    queue<node> Q;
    f[x][y][0]=0;
    Q.push({x,y,0LL});
    while(!Q.empty()){
        node u=Q.front();
        Q.pop();
        if(u.s==0){
            cout<<f[u.s][u.w][u.b]<<'\n';
            return;
        }
        if(u.b==0){
            for(int i=0;i<=u.s;i++){
                for(int j=0;j<=u.w;j++){
                    if(i+j>p)break;
                    int ns=u.s-i,nw=u.w-j;
                    if(ns>0&&nw>ns+q) continue;
                    if(f[ns][nw][1]==-1){
                        f[ns][nw][1]=f[u.s][u.w][0]+1;
                        Q.push({ns,nw,1});
                    }
                }
            }
        }else{
            int sd=x-u.s,wd=y-u.w;
            for(int i=0;i<=sd;i++){
                for(int j=0;j<=wd;j++){
                    if(i+j>p)break;
                    int ns=u.s+i,nw=u.w+j;
                    if(x-ns>0&&y-nw>x-ns+q) continue;
                    if(f[ns][nw][0]==-1){
                        f[ns][nw][0]=f[u.s][u.w][1]+1;
                        Q.push({ns,nw,0});
                    }
                }
            }
        }
    }
    cout<<-1<<'\n';
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
 