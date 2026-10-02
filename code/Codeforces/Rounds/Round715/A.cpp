#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%2==0) a.push_back(x);
        else b.push_back(x);
    }
    for(int x:a) cout<<x<<" ";
    for(int x:b) cout<<x<<" ";
    cout<<'\n';

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}