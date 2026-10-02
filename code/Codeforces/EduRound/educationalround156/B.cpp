#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

void solve(){
    double tx,ty;
    cin>>tx>>ty;
    double ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;


    double l=0.0,r=11451419191.0;
    for(int i=0;i<100;i++){
        double mid=(l+r)/2;
        double d1=(tx-ax)*(tx-ax)+(ty-ay)*(ty-ay);
        double d2=(tx-bx)*(tx-bx)+(ty-by)*(ty-by);
        double o1=ax*ax+ay*ay;
        double o2=bx*bx+by*by;
        double dis=(ax-bx)*(ax-bx)+(ay-by)*(ay-by);
        if((d1<=mid*mid&&o1<=mid*mid)||(d2<=mid*mid&&o2<=mid*mid)||(d1<=mid*mid&&o2<=mid*mid&&dis<=4*mid*mid)||(d2<=mid*mid&&o1<=mid*mid&&dis<=4*mid*mid)){
            r=mid;
        }
        else l=mid;
    }
    cout<<fixed<<setprecision(10);
    cout<<r<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}