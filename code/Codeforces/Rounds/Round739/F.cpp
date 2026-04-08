#include<bits/stdc++.h>
using namespace std;
#define int long long
int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a;
        a=a*a;
        n>>=1;
    }
    return res;
}


void solve(){
    int n,k;
    cin>>n>>k;

    int res=2e9;

    for(int b=2;b<(1<<(10));b++){
        if(__builtin_popcount(b)!=k) continue;
        int h=__lg(b);
        int l=__builtin_ctz(b);
        
        int x=0;
        for(int i=9;i>=0;i--){
            int d=n/qp(10,i)%10;
            if((b>>d&1) || (x==0 && d==0)){
                if((qp(10,i)-1)/9*h>=n%qp(10,i)){
                    x+=1LL*d*qp(10,i);
                    continue;
                }
            }
            d++;
            while(~b>>d&1){
                d++;
            }
            x+=d*qp(10,i);
            x+=(qp(10,i)-1)/9*l;
            break;
        }
        res=min(res,x);
    }

    cout<<res<<'\n';

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