#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<double> a(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i]=atan2(y,x);
    } 
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        a.push_back(a[i]+2*PI);
    }
    

    double mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,a[i+k]-a[i]);
    }
    cout<<fixed<<setprecision(10)<<mx<<'\n';


    
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

