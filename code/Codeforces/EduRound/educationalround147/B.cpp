#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int l=0,r=n-1;
    while(a[l]==b[l] && l<n) l++;
    while(a[r]==b[r] && r>=0) r--;
    if(l>=r){
        cout<<1<<" "<<n<<'\n';
        return;
    }

    while(l>0 && b[l]>=b[l-1]) l--;
    while(r+1<n && b[r]<=b[r+1]) r++;
    cout<<l+1<<" "<<r+1<<'\n';

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