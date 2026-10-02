#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    int len=0;
    int i=0,j=0;
    while(i<n && j<m && s[i]==t[j]){
        i++,j++;
        len++;
    }
    int res=len+(len?1:0)+n-len+m-len;
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