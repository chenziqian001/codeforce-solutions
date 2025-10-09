#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int h,d;
    cin>>h>>d;
    auto check=[&](int mid){
        int s=mid+1;
        int a=d/s;
        int r=d%s;
        int cost=r*(a+1)*(a+2)/2+(s-r)*(a+1)*a/2;
        return cost<=h+mid-1;
    };
    int l=0,r=d*2;
    int res=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
        
    }
    cout<<res+d<<'\n';
    
}

signed main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int T;
    cin>>T;
    while(T--) solve();
    system("pause");
    return 0;
}




