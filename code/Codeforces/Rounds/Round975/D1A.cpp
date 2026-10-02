#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=accumulate(a.begin(),a.end(),0LL);
    int mx=*max_element(a.begin(),a.end());
    for(int s=n;s>=1;s--){
        int d=max((sum+s-1)/s,mx);
        if(k>=s*d-sum){
            cout<<s<<'\n';
            return;
        }
    }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    //system("pause");
    return 0;
}


