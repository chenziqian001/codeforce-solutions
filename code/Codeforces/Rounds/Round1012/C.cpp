#include<bits/stdc++.h>
using namespace std;
#define int long long
int calc(int x,int y){
    if(x%3!=2 || y%3!=2){
        return x+y;
    }
    return x+y+2;
}
struct node{
    int x,y;
    bool operator < (const node &a) const {
        if(calc(x,y)!=calc(a.x,a.y)) return calc(x,y)<calc(a.x,a.y);
        if(x!=a.x) return x<a.x;
        return y<a.y;
    }
};
set<node> a;
set<node> b;

void solve(){
    int n;
    cin>>n;
    a.clear();
    b.clear();
    for(int i=1;i<=2*sqrt(n);i++){
        for(int j=1;j<=2*sqrt(n);j++){
            a.insert((node){(i-1)*3+1,(j-1)*3+1});
            for(int x=0;x<2;x++){
                for(int y=0;y<2;y++){
                    b.insert((node){(i-1)*3+x+1,(j-1)*3+y+1});
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        int g;
        cin>>g;
        if(g==1){
            node k=*b.begin();
            cout<<k.x<<" "<<k.y<<'\n';
            b.erase(b.begin());
            a.erase(k);
        }
        else{
            node k=*a.begin();
            cout<<k.x<<" "<<k.y<<'\n';
            a.erase(k);
            if(k.x%3==1 && k.y%3==1) b.erase(k);
        }
    }
}


signed main(){
    int t;
    cin>>t;
    while(t--) solve();

    system("pause");  // 只在 Windows 下生效

    return 0;
}