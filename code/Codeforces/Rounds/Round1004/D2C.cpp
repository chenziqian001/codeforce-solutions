#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    for(int l=0;l<=9;l++){
        string s=to_string(n-l);
        int mx=0;
        for(char c:s){
            if(c<='7') mx=max(mx,c-'0');
        }

        if(l>=7-mx){
            cout<<l<<'\n';
            return;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}