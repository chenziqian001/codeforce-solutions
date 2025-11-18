#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e4+10;
int f[N][23];
int year[N];
int rain[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>year[i]>>rain[i];
        f[i][0]=rain[i];
    }
    for(int j=0;j<20;j++){
        for(int i=1;i+(1<<(j+1))-1<=n;i++){
            f[i][j+1]=max(f[i][j],f[i+(1<<j)][j]);
        }
    }
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x>=y) {
            cout<<"false"<<'\n';
            continue;
        }
        bool a=0,b=0;
        int pos1=lower_bound(year+1,year+1+n,x)-year;
        int pos2=lower_bound(year+1,year+1+n,y)-year;
        if(year[pos1]==x) a=1;
        if(year[pos2]==y) b=1;
        if(!a){
            pos1--;
        }
        int k=log2(pos2-pos1-1);
        int mx=0;
        if(pos1+1<=pos2-1){
            mx=max(f[pos1+1][k],f[pos2-(1<<k)][k]);
        }
        if(a && mx>=rain[pos1]){
            cout<<"false"<<'\n';
            continue;
        }
        if(b && mx>=rain[pos2]){
            cout<<"false"<<'\n';
            continue;
        }
        if(a&&b&&rain[pos1]<rain[pos2]){
            cout<<"false"<<'\n';
            continue;
        }
        if(a==0 || b==0){
            cout<<"maybe"<<'\n';
            continue;
        }
        if(year[pos2]-year[pos1]!=pos2-pos1){
            cout<<"maybe"<<'\n';
            continue;
        }
        cout<<"true"<<'\n';
    }
    //system("pause");
}
/*
6
2002 4920
2003 5901
2004 2832
2005 3890
2007 5609
2008 3024
5
2002 2005
2003 2005
2002 2007
2003 2007
2005 2008

*/
