#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int x;
    cin>>x;
    if(x==0){
        cout<<0<<"\n";
        return;
    }
    int ans=x,S=sqrt(x);
    for(int a=S;a>=1;--a){
        if((x+a)/(a+1)-a>=ans) break;
        int cd[4]={x/(a+1),x/(a+1)+1,x/a-1,x/a};
        for(int i=0;i<4;i++){
            int b=cd[i];
            if(b<a) b=a;
            if(b>x/a) continue;
            int c=x-a*b;
            ans=min(ans,max({a,b,c})-min({a,b,c}));
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}