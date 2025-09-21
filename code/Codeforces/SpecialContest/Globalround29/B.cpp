#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    for(int i=n;i>=1;i--){
        cout<<i<<" ";
    }
    cout<<n<<" ";
    for(int i=1;i<=n-1;i++){
        cout<<i<<" ";
    }
    cout<<'\n';

    
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}



