#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int cnt=0;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]) cnt++;
    }
    if(cnt>2){
        cout<<"NO"<<'\n';
    }
    else cout<<"YES"<<'\n';
    
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


