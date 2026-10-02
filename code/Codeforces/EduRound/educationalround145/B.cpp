#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2e9;
void solve(){
    int n;
    cin>>n;
    int l=0,r=inf;
    int res=r;
    while(l<=r){
        int mid=(l+r)/2;
        if((mid+1)*(mid+1)>=n){
            r=mid-1;
            res=mid;
        }
        else l=mid+1;
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
 