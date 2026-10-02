#include<bits/stdc++.h>
#define int long long
using namespace std;
int f(int x){
    if(!x)return 0;
    return 64-__builtin_clzll(x)+__builtin_popcountll(x)-1;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=2e18;
    for(int Z=0;Z<=18;Z++){
        int cur=Z;
        int lim=18/(1LL<<min(10LL,Z))+1;
        for(int i=0;i<n;i++){
            int cmin=(a[i]+(1LL<<Z)-1)>>Z;
            if(!cmin)cmin=1;
            int bst=2e18;
            for(int c=cmin;c<=cmin+lim;c++){
                bst=min(bst,c*(1LL<<Z)+f(c));
            }
            cur+=bst-a[i];
        }
        ans=min(ans,cur);
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}