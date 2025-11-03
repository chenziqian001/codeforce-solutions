#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    set<string> res;
    int mx=0;
    map<string,int> mp;
    for(int i=0;i<=n-k;i++){
        ++mp[s.substr(i,k)];
        if(mp[s.substr(i,k)]>mx){
            mx=mp[s.substr(i,k)];
        }
    }
    for(int i=0;i<=n-k;i++){
        if(mp[s.substr(i,k)]==mx){
            res.insert(s.substr(i,k));
        }
    }
    cout<<mx<<'\n';
    for(string x:res) cout<<x<<" ";
    cout<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    //system("pause");

}