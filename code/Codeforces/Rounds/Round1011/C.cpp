#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int x,y;
    cin>>x>>y;
    if(x==y){
        cout<<-1<<'\n';
        return;
    }
    for(int i=1;i<=64;i++){
        if((1LL<<i)>=max(x,y)){
            cout<<((1LL<<i)-max(x,y))<<'\n';
            return;
        }
    }

}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}

