#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>c(k+1,0);
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        for(int j=0;j<k;j++){
            if(x[j]=='1')c[k-j-1]++;
        }
    }
    vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
    dp[0][0]=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<=n;j++){
            if(dp[i][j]==-1)continue;
            for(int x=0;x<=1;x++){
                int v=x?n-c[i]:c[i];
                if((v+j)%2==(s[k-i-1]-'0')){
                    int nc=(v+j)/2;
                    if(nc<=n)dp[i+1][nc]=x;
                }
            }
        }
    }
    if(dp[k][0]==-1){
        cout<<"-1\n";
        return;
    }
    string res="";
    int b=0;
    for(int i=k-1;i>=0;i--){
        int x=dp[i+1][b];
        res+=x+'0';
        int v=x?n-c[i]:c[i];
        b=b*2+s[k-1-i]-'0'-v;
    }
    cout<<res<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}