#include<bits/stdc++.h>
using namespace std;
#define int long long



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s,n,m;
    cin>>s>>n>>m;

    vector<vector<int>> a(n,vector<int>(s));

    for(int i=0;i<s;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            x=x*2+1;
            a[j][i]=x;
        }
    }
    for(int i=0;i<n;i++) sort(a[i].begin(),a[i].end());

    vector<int> dp(m+1);

    for(int i=0;i<n;i++){
        for(int j=m;j>=0;j--){
            for(int k=0;k<s;k++){
                if(j>=a[i][k]){
                    dp[j]=max(dp[j],dp[j-a[i][k]]+(k+1)*(i+1));
                }
            }
        }
    }

    cout<<dp[m]<<'\n';
    //system("pause");
    return 0;
}