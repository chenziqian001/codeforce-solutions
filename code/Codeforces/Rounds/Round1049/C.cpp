#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1){
        cout<<a[0]<<'\n';
        return;
    }
    int tt=0;
    for(int i=0;i<n;i++){
        if(i%2==0) tt+=a[i];
        else tt-=a[i];
    }
    if(n==1){
        cout<<tt<<'\n';
        return;
    }
    int res=tt;
    int minieven=1e15;
    int miniodd=1e15;
    if(n&1) res=res+n-1;
    else res+=n-2;
    for(int i=0;i<n;i++){
        if(i&1) res=max(res,tt+i+a[i]*2-minieven),miniodd=min(miniodd,i-a[i]*2);
        else res=max(res,tt+i-a[i]*2-miniodd),minieven=min(minieven,i+a[i]*2);
    }
    cout<<res<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;

}