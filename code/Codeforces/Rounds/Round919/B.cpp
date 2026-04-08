#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k,x;
    cin>>n>>k>>x;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];



    sort(a.rbegin(),a.rend());


    int sum=accumulate(a.begin(),a.end(),0LL);
    
    for(int i=0;i<x;i++){
        sum-=2*a[i];
    }

    int res=sum;
    
    for(int i=0;i<k;i++){
        sum+=a[i];
        if(i+x<n){
            sum-=2*a[i+x];
        }

        res=max(res,sum);
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
