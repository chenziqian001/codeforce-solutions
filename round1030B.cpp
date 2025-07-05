#include<iostream>
#include<vector>
using namespace std;


void solve(){
    int n;
    cin>>n;

    cout<<2*n-1<<'\n';
    cout<<1<<" "<<1<<" "<<n<<'\n';
    for(int i=1;i<n;i++){
        cout<<i+1<<" "<<1<<" "<<i<<'\n';
        cout<<i+1<<" "<<i+1<<" "<<n<<'\n';
    }
    return;
}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}