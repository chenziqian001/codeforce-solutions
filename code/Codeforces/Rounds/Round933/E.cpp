#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m,k,d;
    cin>>n>>m>>k>>d;

    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int sum=0;
    int res=1e18;


    vector<int> done(n);

    for(int i=0;i<n;i++){
        vector<int> dp(m);
        dp[0]=1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({1,0});
        for(int j=1;j<m;j++){
            while((j-pq.top().second)-1>d){
                pq.pop();
            }
            if(!pq.empty()){
                int val=pq.top().first;
                dp[j]=a[i][j]+1+val;
            }
            pq.push({dp[j],j});
        }
        done[i]=dp[m-1];
        sum+=done[i];
        if(i>=k){
            sum-=done[i-k];
            res=min(res,sum);
        }
        if(i>=k-1){
            res=min(res,sum);
        }
    }
    cout<<res<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}