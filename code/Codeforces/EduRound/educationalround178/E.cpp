#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
int q;
void solve(){
    cin>>n>>k;
    cin>>s;
    vector<int> dis(n+1);
    vector<vector<int>> dp(n+2,vector<int>(k,n));
    for(int i=n-1;i>=0;i--){
        dp[i]=dp[i+1];
        
        int mx=*max_element(dp[i].begin(),dp[i].end());
        dis[i]=dis[mx]+1;
        dp[i][s[i]-'a']=i;
    }


    cin>>q;
    while(q--){
        string t;
        cin>>t;
        int pos=-1;
        for(char c:t){
            pos=dp[pos+1][c-'a'];
        }
        cout<<dis[pos]<<'\n';
    }

}

int main(){
    solve();
    system("pause");
    return 0;
}
