#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k,p,q;
    cin>>n>>k>>p>>q;
    vector<int> a(n);
    vector<int> ca(n),cb(n);
    int res=0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        int A=a[i]%p;
        int B=(a[i]%q)%p;
        int mn=min(A,B);
        res+=mn;
        ca[i]=A-mn;
        cb[i]=B-mn;
    }
    int mca=2e18,mcb=2e18;
    int sa=0,sb=0;
    for(int i=0;i<k;i++){
        sa+=ca[i];
        sb+=cb[i];
    }
    mca=sa;
    mcb=sb;
    for(int i=k;i<n;i++){
        sa+=ca[i]-ca[i-k];
        sb+=cb[i]-cb[i-k];
        mca=min(mca,sa);
        mcb=min(mcb,sb);
    }
    cout<<res+min(mca,mcb)<<'\n';

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