#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b.begin(),b.end());
    int k=0,sum=0;
    for(int i=0;i<n;i++){
        if(sum+b[i]<=m){
            sum+=b[i];
            k++;
        }else break;
    }
    if(k==n){
        cout<<1<<'\n';
        return;
    }
    if(k>0 && sum-b[k-1]+a[k]<=m) cout<<n-k<<'\n';
    else cout<<n-k+1<<'\n';
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
 