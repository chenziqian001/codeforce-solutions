#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    bitset<N> dp {};
    dp[1]=1;
    int res=0;

    for(int i=1;i<=n;i++){
        dp|=(dp<<a[i]);
        if(dp[i]){
            dp[i]=0;
            res=max(res,s[i]-i+1);
        }
    }    

    for(int i=n;i<=2*n;i++){
        if(dp[i]) res=max(res,s[n]-i+1);
    }
    cout<<res<<'\n';
    //system("pause");


}




