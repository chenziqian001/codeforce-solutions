#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    long long ans=0;
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-1-i;j++){
            char c1=s[i][j];
            char c2=s[j][n-1-i];
            char c3=s[n-1-i][n-1-j];
            char c4=s[n-1-j][i];
            char m=max({c1,c2,c3,c4});
            ans+=(m-c1)+(m-c2)+(m-c3)+(m-c4);
        }
    }
    cout<<ans<<'\n';
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