#include<bits/stdc++.h>
using namespace std;




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int m=sqrt(n);
    vector<vector<int>> dp(n+1,vector<int>(m+1));


    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            if(i+a[i]+j>n) dp[i][j]=1;
            else dp[i][j]=dp[i+a[i]+j][j]+1;
        }
    }


    int q;
    cin>>q;
    while(q--){
        int p,k;
        cin>>p>>k;
        if(k<=m) cout<<dp[p][k]<<'\n';
        else{
            int cnt=0;
            while(p<=n){
                p=p+a[p]+k;
                cnt++;
            }
            cout<<cnt<<'\n';
        }
    }

    //system("pause");
    return 0;

}