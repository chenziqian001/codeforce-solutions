#include<bits/stdc++.h>
using namespace std;
#define int long long
int l,r;


int luck(int x){
    string s=to_string(x);
    auto [mini,maxi]=minmax_element(s.begin(),s.end());
    return *maxi-*mini;
}

void solve(){
    cin>>l>>r;
    int res=l;
    int p=1;
    for(int i=0;i<=18;i++){
        for(int x=0;x<10;x++){
            int v=l/p*p+(p-1)/9*x;
            if(l<=v && v<=r && luck(v)<luck(res)){
                res=v;
            }
            v=r/p*p+(p-1)/9*x;
            if(l<=v && v<=r && luck(v)<luck(res)){
                res=v;
            }
        }
        p*=10;
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