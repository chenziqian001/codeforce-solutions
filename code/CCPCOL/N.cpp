#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    bool ok=false;
    if(m>=50) ok=true;
    if(s[1]>='4') ok=true;
    double k=(double)m/(double)n;
    if(k>=0.2) ok=true;
    if(ok){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';

}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
}