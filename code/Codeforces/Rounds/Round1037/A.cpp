#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x;
    cin>>x;
    string s=to_string(x);
    int n=s.size();
    char mini='9';
    for(int i=0;i<n;i++){
        mini=min(mini,s[i]);
    }
    int res=mini-'0';
    cout<<res<<'\n';

}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}