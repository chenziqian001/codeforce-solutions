#include<bits/stdc++.h>
using namespace std;


void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int d=b+c;
    
    if(a<=d+1){
        cout<<a*2-1<<'\n';
        return;
    }
    else{
        cout<<d*2+1<<'\n';
        return;
    }


   

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}