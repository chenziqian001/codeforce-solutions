#include<bits/stdc++.h>
using namespace std;
#define int long long

int ask(int i,int j){
    cout<<'?'<<" "<<i<<" "<<j<<endl;
    int res;
    cin>>res;
    return res;
}

void solve(){
    int n;
    cin>>n;

    for(int i=1;i<2*n-2;i+=2){
        if(ask(i,i+1)){
            cout<<'!'<<" "<<i<<endl;
            return;
        }        
    }


    if(ask(1,2*n)){
        cout<<'!'<<" "<<1<<endl;
    }
    else if(ask(2,2*n)){
        cout<<'!'<<" "<<2<<endl;
    }
    else{
        cout<<'!'<<" "<<2*n-1<<endl;
    }
}
signed main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}







