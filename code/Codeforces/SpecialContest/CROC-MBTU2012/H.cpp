#include<bits/stdc++.h>
using namespace std;




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    s=' '+s;

    vector<vector<int>> dp(n+1,vector<int>(n+1));
    vector<vector<int>> is(n+1,vector<int>(n+1,false));
    for(int i=1;i<=n;i++){
        dp[i][i]=1;
        is[i][i]=true;
    }


    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            bool ok;
            if(len==2){
                ok=(s[i]==s[j]);
            }
            else{
                ok=(is[i+1][j-1] && (s[i]==s[j]));
            }
            is[i][j]=ok;
            dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            if(is[i][j]) dp[i][j]++;
        }
    }
    
    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<dp[l][r]<<'\n';
    }
    //system("pause");
    return 0;
}