#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    if(n%2==1||(n-1)%4!=3){
        cout<<"Alice"<<'\n';
    }
    else cout<<"Bob"<<'\n';


}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}
