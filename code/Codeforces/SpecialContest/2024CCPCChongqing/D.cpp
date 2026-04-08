#include<bits/stdc++.h>
using namespace std;
#define int long long


int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    int g=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return g;
}



void solve(){
    int a,b;
    cin>>a>>b;
    int w=b;
    while(w%2==0) w/=2;
    while(w%5==0) w/=5;
    int b1=b/w,ac=2e18,ad=2e18,k,c0;
    exgcd(b1%w,w,c0,k);

    for(int z=1;z*w<=1000000000;z*=5){
        for(int d=z;d*w<=1000000000;d*=2){
            int c=(int)((-(__int128)c0*a*d%w+w)%w);        
            if(c<ac){
                ac=c;
                ad=d*w;
            }else if(c==ac&&d*w<ad){
                ad=d*w;
            }
        }
    }
    cout<<ac<<" "<<ad<<"\n";


}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}