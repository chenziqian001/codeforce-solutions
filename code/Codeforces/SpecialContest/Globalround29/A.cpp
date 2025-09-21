#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x,y;
    cin>>x>>y;
    if(x<y){
        cout<<2<<'\n';
    }
    else{
        if(1+y>=x || y==1){
            cout<<-1<<'\n';
        }
        else{
            cout<<3<<'\n';
        }
    }
    
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}