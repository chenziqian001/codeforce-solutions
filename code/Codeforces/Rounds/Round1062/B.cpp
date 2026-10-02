#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    vector<int> cnt(26);
    for(int i=0;i<n;i++){
        cnt[s[i]-'a']++;
        cnt[t[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(cnt[i]!=0){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';
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