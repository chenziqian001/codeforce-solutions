#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>b[i];
    }

    int curg=1;
    int curl=0;
    int res=1;
    curg=a[0]*b[0];
    curl=b[0];

    for(int i=1;i<n;i++){
        curg=__gcd(curg,a[i]*b[i]);
        curl=(curl/__gcd(curl,b[i]))*b[i];
        if(curg%curl!=0){
            res++;
            curg=a[i]*b[i];
            curl=b[i];
        }
    }
    cout<<res<<'\n';





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