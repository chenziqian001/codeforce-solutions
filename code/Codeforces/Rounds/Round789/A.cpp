#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }

    vector<int> cnt(n);


    int res=0;
    for(int b=0;b<n;b++){
        int d=0;
        for(int c=n-1;c>b;c--){
            res+=cnt[c]*d;
            d+=a[c]<a[b];
            cnt[c]+=a[b]<a[c];
        }
    }

    cout<<res<<'\n';


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