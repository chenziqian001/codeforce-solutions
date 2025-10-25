#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    int l=0,r=n+1;
    int ml=m,mr=m;
    while(q--){
        int x;
        cin>>x;
        if(l){
            if(x>l){
                l++;
                l=min(l,n);
            }
        }
        if(r<=n){
            if(x<r){
                r--;
                r=max(1LL,r);
            }
        }

        if(ml){
            if(x<ml){
                ml--;
                ml=max(1LL,ml);
            }
            else if(x>mr){
                mr++;
                mr=min(mr,n);
            }
            else{
                if(ml==mr){
                    ml=mr=0;
                }
                l=max(l,1LL);
                r=min(n,r);
            }
        }
        int res=l;
        ml=max(l+1,ml);
        res+=max(0LL,mr-ml+1);
        res+=n-max({mr+1,r,l+1})+1;
        cout<<res<<" ";
    }
    cout<<'\n';


}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}



        

