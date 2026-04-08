#include<bits/stdc++.h>
using namespace std;
#define int long long




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);   

    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());

    int base=a[0];
    vector<int> v;
    for(int i=1;i<a.size();i++){
        v.push_back(a[i]-base);
    }


    int mxdiff=v.empty()?0:v.back()*k;
    vector<int> dp(mxdiff+1,1e9);

    dp[0]=0;
    for(int x:v){
        for(int j=x;j<=mxdiff;j++){
            dp[j]=min(dp[j],dp[j-x]+1);
        }
    }


    for(int j=0;j<=mxdiff;j++){
        if(dp[j]<=k) cout<<base*k+j<<" ";
    }
    cout<<'\n';
    //system("pause");

}