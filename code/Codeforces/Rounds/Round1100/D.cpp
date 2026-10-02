#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    auto check=[&](int x)->bool{
        int c2=0,c0=0;
        bool in0=false;
        for(int i=0;i<n;i++){
            int c=(a[i]>=x)+(b[i]>=x);
            if(c==2){
                c2++;
                in0=false;
            }else if(c==0){
                if(!in0){
                    c0++;
                    in0=true;
                }
            }
        }
        return c2>c0;
    };
    int l=1,r=2*n;
    int res=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
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
