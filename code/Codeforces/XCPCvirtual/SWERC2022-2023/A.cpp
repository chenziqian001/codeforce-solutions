#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> t;
    int pre=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        t.push_back(a-pre);
        pre=a;
    }
    t.push_back(1440-pre);
    int res=0;
    for(int x:t){
        res+=(x/120);
    }
    if(res>=2){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';

    
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