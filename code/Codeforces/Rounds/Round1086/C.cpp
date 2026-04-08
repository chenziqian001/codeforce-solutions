#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> c(n+1);
    vector<double> p(n+1);
   
    for(int i=1;i<=n;i++) {
        cin>>c[i];
        cin>>p[i];
        p[i]=1.00-p[i]/100.00;
    }


    double res=0;
    for(int i=n;i>=1;i--){
        res=max(res*p[i]+c[i],res);
    }
    

    cout<<fixed<<setprecision(9)<<res<<'\n';
    
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
