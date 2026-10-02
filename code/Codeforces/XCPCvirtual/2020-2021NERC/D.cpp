#include<bits/stdc++.h>
using namespace std;
#define int long long
int qp(int a,int b){
    int r=1;
    while(b){
        if(b&1)r=r*a%1000000007;
        a=a*a%1000000007;
        b>>=1;
    }
    return r;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int d=1,c=0;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            d++;
            if(a[i]==a[i-1]+1)c++;
        }
    }
    int p=qp(2,n-d);
    int ans=p;
    if(a[0]==-1)ans=(ans+p*c)%1000000007;
    cout<<ans<<"\n";
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