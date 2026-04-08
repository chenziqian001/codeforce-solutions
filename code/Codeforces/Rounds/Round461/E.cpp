#include<bits/stdc++.h>
using namespace std;
#define int long long




signed main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);   


    int n,W,B,X;
    cin>>n>>W>>B>>X;


    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];
    int mx=accumulate(c.begin(),c.end(),0LL);
    

    vector<int> dp(mx+1,-1);
    dp[0]=W;

    vector<int> cost(n);
    for(int i=0;i<n;i++) cin>>cost[i];

    int sum=0;

    for(int i=0;i<n;i++){
        for(int k=0;k<c[i];k++){
            for(int j=sum;j>=0;j--){
                if(dp[j]>=cost[i]){
                    dp[j+1]=max(dp[j+1],dp[j]-cost[i]);

                }
                
            }
            sum++;
        }


        for(int j=0;j<=sum;j++){
            if(dp[j]!=-1){
                dp[j]=min(dp[j]+X,W+j*B);
            }
        }



    }

    for(int i=mx;i>=0;i--){
        if(dp[i]!=-1){
            cout<<i<<'\n';
            break;
        }
    }
    //system("pause");
    return 0;



}