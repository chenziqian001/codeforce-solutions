#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 

void solve(){
    string s;
    cin >> s;
    
    string t="314159265358979323846264338327";
    
    int res=0;
    while (res<s.size() && s[res] == t[res]) res++;
    
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