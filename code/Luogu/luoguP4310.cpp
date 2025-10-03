#include<bits/stdc++.h>
using namespace std;
int dp[32];

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int res=0;
    for(int i=0;i<n;i++){
        int k=1;
        for(int j=0;j<=31;j++){
            if(a[i]&(1<<j)) k=max(dp[j]+1,k);
        }
        for(int j=0;j<=31;j++){
            if(a[i]&(1<<j)) dp[j]=max(dp[j],k);
        }
        res=max(res,k);
    }
    cout<<res<<'\n';
    return 0;
}