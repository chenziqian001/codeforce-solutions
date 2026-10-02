#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int dp[705][705][3][3];
bool vis[705][705];
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> mt(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(s[i]=='(') st.push(i);
        else{
            mt[st.top()]=i;
            mt[i]=st.top();
            st.pop();
        }
    }

    function<void(int,int)> dfs=[&](int l,int r){
        if(l>r) return;
        if(vis[l][r]) return;
        vis[l][r]=true;
        if(l+1==r){
            dp[l][r][0][1]=1;
            dp[l][r][0][2]=1;
            dp[l][r][1][0]=1;
            dp[l][r][2][0]=1;
            return;
        }
        if(mt[l]==r){
            dfs(l+1,r-1);
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if((i==0 && j==0) ||(i!=0 && j!=0)) continue;
                    for(int u=0;u<3;u++){
                        for(int v=0;v<3;v++){
                            if((i!=0&&i==u) ||(j!=0&&j==v)) continue;
                            dp[l][r][i][j]=(dp[l][r][i][j]+dp[l+1][r-1][u][v])%mod;
                        }
                    }
                }
            }
        }
        else{
            int k=mt[l];
            dfs(l,k);
            dfs(k+1,r);
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    for(int u=0;u<3;u++)
                        for(int v=0;v<3;v++){
                            if(j!=0&&j==u) continue;
                            dp[l][r][i][v]=(dp[l][r][i][v]+dp[l][k][i][j]*dp[k+1][r][u][v])%mod;
                        }
        }
    };
    dfs(0,n-1);
    int res=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            res=(res+dp[0][n-1][i][j])%mod;
        }
    }
    cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    //system("pause");
    return 0;
}
