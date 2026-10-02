#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int res=0;
    for(int i=1;i<n;i++){
        if(s[i]=='0' && s[i-1]=='1') res++;
    }
    cout<<res<<'\n';
    
 
}
 
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}
 
 