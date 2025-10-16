#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+1;


int main(){
    int n,q;
    cin>>n>>q;
    vector<pair<int,int>> a(q);
    vector<int> mxlen(n);
    for(int i=0;i<q;i++){
        int id;char c;
        cin>>id>>c;
        id--;
        if(c=='+'){
            a[i]=make_pair(id,1);
            mxlen[id]++;
        }
        else{
            a[i]=make_pair(id,-1);
        }
    }
    vector<vector<int>> dis(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            int mini=inf;
            int cur=0;
            for(auto [id,op]:a){
                if(id==i && op==1) cur--;
                if(id==j && op==-1) cur++;
                mini=min(mini,cur);
            }
            if(mini>=0){
                dis[i][j]=1;
            }
            else dis[i][j]=-mini+1;
        }
    }
    vector<vector<int>> dp(1<<n,vector<int>(n,inf));
    for(int i=0;i<n;i++) dp[1<<i][i]=1;
    for(int st=1;st<(1<<n);st++){
        for(int i=0;i<n;i++){
            if(dp[st][i]==inf) continue;
            for(int j=0;j<n;j++){
                if(!(st&(1<<j))){
                    int nxst=st|(1<<j);
                    dp[nxst][j]=min(dp[nxst][j],dp[st][i]+dis[i][j]);
                }
            }
        }
    }
    int ans=inf;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[(1<<n)-1][i]+mxlen[i]);
    }
    cout<<ans<<'\n';
    system("pause");
    return 0;
}