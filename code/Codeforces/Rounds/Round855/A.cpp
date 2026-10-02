#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int j=0;
    for(int i=0;i<4;i++) {
        char lo="meow"[i];
        char up="MEOW"[i];
        if (j==n || (s[j]!=lo && s[j]!=up)) {
            cout<<"NO"<<'\n';
            return;
        }
        while (j<n && (s[j]==lo || s[j]==up)) {
            j++;
        }
    }
    if(j==n){
        cout<<"YES"<<'\n';
    } else {
        cout<<"NO"<<'\n';
    }
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
