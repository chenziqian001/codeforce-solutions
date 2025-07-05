#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int dp[11];




void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> bx(m,vector<int>(3));
    for(int i=0;i<m;i++){
        cin>>bx[i][0]>>bx[i][1]>>bx[i][2];
    }
    int fi=dp[n];
    int sc=dp[n-1];
    string str;
    for(int i=0;i<m;i++){

        int maxi=max({bx[i][0],bx[i][1],bx[i][2]});
        int mini=min({bx[i][0],bx[i][1],bx[i][2]});
        if(mini>=fi&&maxi>=fi+sc){
            str+='1';
        }
        else str+='0';
    }
    cout<<str<<'\n';
    return;
}



int main(){
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=10;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}