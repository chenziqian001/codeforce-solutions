#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int la,ra,lb,rb;
    cin>>la>>ra>>lb>>rb;
    int l=la+lb,r=ra+rb;
    int d=r-l;
    if(d>=10){
        cout<<9<<'\n';
        return;
    }
    char mx='0';
    for(int i=l;i<=r;i++){
        string s=to_string(i);
        for(char c:s){
            mx=max(mx,c);
        }
    }
    cout<<mx<<'\n';

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



