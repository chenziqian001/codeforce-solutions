#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) {
        cout<<n-p[i]+1<<" ";
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