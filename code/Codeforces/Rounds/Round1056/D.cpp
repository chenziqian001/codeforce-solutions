#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    int f;
    for(int d=1;d<n;d++){
        for(int i=1;i+d<=n;i++){
            cout<<i<<" "<<i+d<<'\n';
            cin>>f;
            if(f) return;
        }
    }







}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}