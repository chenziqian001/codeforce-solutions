#include<iostream>
#include<vector>

using namespace std;


void solve(){
    int n;
    cin>>n;
    cout<<1<<" ";
    for(int i=n;i>=2;i--){
        cout<<i<<" ";
    }
    cout<<'\n';
    return;


}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;

}