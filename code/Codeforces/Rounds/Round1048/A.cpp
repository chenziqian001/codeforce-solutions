#include<bits/stdc++.h>
using namespace std;


void solve(){
    int a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    if(a==b){
        cout<<0<<'\n';
        return;
    }
    else if(b%a==0){
        cout<<1<<'\n';
    }
    else{
        cout<<2<<'\n';
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;

}