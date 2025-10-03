#include<bits/stdc++.h>
using namespace  std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(k==1){
        int l=*max_element(a.begin(),a.end()-1);
        int r=*max_element(a.begin()+1,a.end());
        long long res=max(l+a[n-1],r+a[0]);
        cout<<res<<'\n';
    }
    else{
        sort(a.rbegin(),a.rend());
        long long ans=0;
        for(int i=0;i<k+1;i++) ans+=a[i];
        cout<<ans<<'\n';
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}