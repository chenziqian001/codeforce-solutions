#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef __int128_t lll;
typedef long long ll;

void solve(){
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    
    auto check=[&](lll mid){
        lll cnt=0;
        for(lll d=1;;d++){
            lll mv=(lll)a*d*d+2*(lll)a*d+2*(lll)b*d;
            if(mv>mid)break;
            lll mx=(mid-(lll)a*d*d-2*(lll)b*d)/(2*(lll)a*d);
            if(mx>n-d)mx=n-d;
            if(mx>0)cnt+=mx;
        }
        return cnt;
    };

   
    lll l=0,r=1;
    while(check(r)<k)r*=2;

    lll ans=r;
    while(l<=r){
        lll mid=l+(r-l)/2;
        if(check(mid)>=k){ans=mid;r=mid-1;}
        else l=mid+1;
    }
    
    lll p=ans,q=a;
    while(q){lll t=p%q;p=q;q=t;}
    cout<<(ll)(ans/p)<<" "<<(ll)(a/p)<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}