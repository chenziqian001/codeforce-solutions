#include<bits/stdc++.h>
using namespace std;
#define int long long

int ask(int a,int b){
    int res;
    cout<<'?'<<" "<<a<<" "<<b<<endl;
    cin>>res;
    return res;    
}
void solve() {
    int res=0;
    for(int i=0;i<30;i++){
        int a=(1LL<<i)-res;
        int b=a+(1LL<<(i+1));
        if(ask(a,b)==(1LL<<(i+1))){
            res|=(1LL<<i);
        }
    }
    cout<<'!'<<" "<<res<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--) solve();
    //system("pause");
    return 0;
}