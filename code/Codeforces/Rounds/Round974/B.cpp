#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    long long res=1LL*k*(n+n-k+1)/2;

    if(res%2==1){
        cout<<"NO"<<'\n';

    }
    else{
        cout<<"YES"<<'\n';
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