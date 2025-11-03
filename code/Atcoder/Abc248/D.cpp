#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int x){
    int y=sqrt(x);
    while(y*y>x) y--;
    while((y+1)*(y+1)<=x) y++;
    return y;
}
int solve(int c,int d){
    int res=0;
    int xmin=1,xmax=9,shift=10;
    while(xmin<=c+d){
        int l=max(xmin,c+1);
        int r=min(xmax,c+d);
        if(l<=r){
            int vl=c*shift+l;
            int vr=c*shift+r;
            res+=f(vr)-f(vl-1);
        }
        xmin*=10;
        xmax=(xmax+1)*10-1;
        shift*=10;
    }

    return res;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int c,d;
        cin>>c>>d;
        cout<<solve(c,d)<<'\n';
    }
}