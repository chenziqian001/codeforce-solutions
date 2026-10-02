#include<bits/stdc++.h>
using namespace std;
#define int long long
 



void solve(){
    int n;
    cin>>n;
    if(n<=3){
        if(n==1){
            cout<<"Fluttershy"<<'\n';
        }
        else{
            cout<<"Pinkie Pie"<<'\n';
        }
    }
    else{
        n-=3;
        if(n%4==1 || n%4==2){
            cout<<"Fluttershy"<<'\n';
        }
        else{
            cout<<"Pinkie Pie"<<'\n';
        }
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
 
 