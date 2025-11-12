#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,m;
    cin>>n>>m;
    m=min(n,m);
    long long res=0;
    for(int j=1;j<=m;j++){
        for(int i=j;i<=n;i+=j){
            if((i/j+1)%j==0){
                res++;
            }
        }
    }

    cout<<res<<'\n';

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