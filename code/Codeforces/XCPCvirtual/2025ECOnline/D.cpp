#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long inf=10000000LL;
const int MOD=998244353;

int qp(int a,int b){
    int r=1;
    while(b){
        if(b&1)r=r*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return r;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> p2(n+1,1),p3(n+1,1);
    for(int i=1;i<=n;i++){
        p2[i]=p2[i-1]*2%MOD;
        p3[i]=p3[i-1]*3%MOD;
    }
    int ans=0,inv2=qp(2,MOD-2);
    for(int i=1;i<=n;i++){
        int c=(p3[i-1]+1)*inv2%MOD;
        int w=p2[n-i];
        int cur=a[i-1]%MOD*w%MOD*c%MOD;
        ans=(ans+cur)%MOD;
    }
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




