#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(a[i]%2) x++;
        else y++;
    }
    if(x && y){
        sort(a.begin(),a.end());
    }
    for(int x:a){
        cout<<x<<" ";
    }
    cout<<'\n';

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