#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.rbegin(),a.rend());

    int len=0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(a[i]) len++;
        sum+=a[i];
    }

    int l=0;
    int r=len;
    int res=0;
    while(l<=r){
        int mid=(l+r)/2;
        int re=sum-mid;

        if(n-1<=re){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
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