#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool ok=false;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            ok=true;
            break;
        }
    }
    if(ok){
        for(int i=0;i<n-1;i++){
            cout<<'&';
        }
        cout<<'\n';
    }
    else{
        if(n%2==0){
            for(int i=0;i<n-1;i++){
                cout<<'^';
            }
            cout<<'\n';
        }
        else{
            cout<<'&';
            for(int i=1;i<n-1;i++){
                cout<<'^';
            }
            cout<<'\n';
        }
    }
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}

