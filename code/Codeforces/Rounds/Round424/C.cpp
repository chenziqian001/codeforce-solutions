#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n,k;
    cin>>n>>k;
    int mx=0;
    int sum=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
        mx=max(mx,x);
        sum+=x;
    }
    sort(a.rbegin(),a.rend());
    int tt=k+sum;
    if(tt/n>mx){
        cout<<tt/n<<'\n';
        return;
    }
    int res=1,l=1;
    while(l<=mx){
        int r=mx,c=n;
        for(int i=0;i<n;i++){
            int b=a[i]-1;
            if(b<l) break;
            int q=b/l;
            c+=q;;
            r=min(r,b/q);
        }
        int up=tt/c;
        if(up>=l) res=max(res,min(r,up));
        l=r+1;
    }
    cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}