#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    cin>>s;
    int res=1;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i==0 && s[i]=='?'){
            res=res*9;
        }
        else if(i==0 && s[i]=='0'){
            cout<<0<<'\n';
            return;
        }
        else if(s[i]=='?'){
            res=res*10;
        }
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