#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2e18;

void solve(){
    int n,h;
    cin>>n>>h;

    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> p(n+2,inf);
    vector<int> s(n+2,inf);
    p[0]=0;
    s[n+1]=0;

    vector<int> f(n+1);
    for(int c=1;c<=n;c++){
        f[c]=a[c];
        for(int i=c-1;i>=1;i--) f[i]=max(f[i+1],a[i]);
        for(int i=c+1;i<=n;i++) f[i]=max(f[i-1],a[i]);
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=f[i];
            p[i]=min(sum,p[i]);
        }

        sum=0;
        for(int i=n;i>=1;i--){
            sum+=f[i];
            s[i]=min(s[i],sum);
        }
    }


    int mini=2e18;
    for(int i=0;i<=n;i++) mini=min(mini,p[i]+s[i+1]);
    cout<<h*n-mini<<'\n';


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
