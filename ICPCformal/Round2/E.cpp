#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
vector<int> fac(11);
void init(){
    fac[0]=1;
    for(int i=1;i<11;i++){
        fac[i]=fac[i-1]*i;
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    else if(n==2){
        cout<<0<<'\n';
        return;
    }
    



}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}