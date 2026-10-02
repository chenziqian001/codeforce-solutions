#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int a,b;
    cin>>a>>b;
    int d=b-a;

    if(d>0){
        if(d>250){
            cout<<"jiu ting tu ran de..."<<'\n';
        }
        else{
            cout<<"nin tai cong ming le!"<<'\n';
        }

    }
    else{
        cout<<"hai sheng ma?"<<'\n';
    }

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