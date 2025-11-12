#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int x,m;
        cin>>x>>m;
        int z=m-m%x;
        int res=z/x;
        if(x<z) res--;
        if((x^z) >=1 && (x^z)<=m) res++;
        if((x^(z+x))>=1 && (x^(x+z))<=m) res++;
        if(x<=m) res--;
        for(int y=1;y<=min(x,m);y++){
            res+=((x^y)%y==0);
        }
        cout<<res<<'\n';
    }
    //system("pause");
}