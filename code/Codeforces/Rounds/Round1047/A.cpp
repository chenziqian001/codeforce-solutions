#include<bits/stdc++.h>
using namespace std;
void solve(){
    int k,x;
    cin>>k>>x;

    cout<<x*(1<<k)<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;

}