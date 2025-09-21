#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    if(n%2==0){
        cout<<n*(n+1)/2<<'\n';
        cout<<1<<" ";
        for(int i=n;i>=2;i--){
            cout<<i<<" ";
        }
    }
    else{
        cout<<n*((n/2)+1)<<'\n';
        for(int i=n;i>=1;i--){
            cout<<i<<" ";
        }
    }
}


int main(){
    solve();
    system("pause");
    return 0;
}