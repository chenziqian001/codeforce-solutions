#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    cin>>s;

    int ans=1e18;
    for(char c='a';c<='z';c++){
        int mx=0,cur=0;
        for(char x:s){
            if(x!=c)cur++;
            else mx=max(mx,cur),cur=0;
        }

        mx=max(mx,cur);
        int op=0;
        while(mx) mx/=2,op++;
        ans=min(ans,op);
    }
    cout<<ans<<"\n";



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