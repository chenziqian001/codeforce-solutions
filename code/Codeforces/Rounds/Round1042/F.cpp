#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a;
    cin>>b;
    vector<int> pa(n),pb(n);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]=='1') cnt++;
        pa[i]=cnt*2-(i+1);
    }
    cnt=0;
    for(int i=0;i<n;i++){
        if(b[i]=='1') cnt++;
        pb[i]=cnt*2-(i+1);
    }
    sort(pb.begin(),pb.end());
    vector<int> ps(n+1);
    for(int i=1;i<=n;i++) ps[i]=ps[i-1]+pb[i-1];
    int res=0;
    for(int i=0;i<n;i++){
        int t=-pa[i];
        int pos=lower_bound(pb.begin(),pb.end(),t)-pb.begin();
        int l=ps[pos],r=ps[n]-l;
        res+=t*pos-l+r-t*(n-pos);
    }
    cout<<(n*n*(n+1)-res)/2<<'\n';
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}