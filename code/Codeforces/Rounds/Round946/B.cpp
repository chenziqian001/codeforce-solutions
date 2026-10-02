#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string r;
    cin>>r;
    string c=r;
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    int m=c.size();
    map<char,char> mp;
    for(int i=0;i<m;i++){
        mp[c[i]]=c[m-i-1];
    }
    for(int i=0;i<n;i++){
        r[i]=mp[r[i]];
    }
    cout<<r<<'\n';    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}