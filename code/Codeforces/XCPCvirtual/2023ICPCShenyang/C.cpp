#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int x,y;
    cin>>x>>y;
    int res=0;
    while(x<3){
        if(x==2 || y==2){
            x++;
            res+=2;
        }
        else{
            x++;
            res++;
        }
    }
    cout<<res<<'\n';

    
}
 
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}
 
 