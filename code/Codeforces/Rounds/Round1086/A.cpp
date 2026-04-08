#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;

    vector<int> cnt(n*n+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            cnt[x]++;
        }
    }
    int bound=n*(n-1);

    for(int i=1;i<=n*n;i++){
        if(cnt[i]>n*(n-1)){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';




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
