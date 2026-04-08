#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    if(a==0){
        cout<<1<<'\n';
    }
    else{
        cout<<a+2*b+1<<'\n';
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}