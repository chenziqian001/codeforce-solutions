#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    for(int i=1;i<n;i++){
        int fa;
        cin>>fa;
        fa--;
        t[fa].push_back(i);
    }
    vector<int> dp(n);
    function<void(int)> dfs=[&](int node)->void{
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int next:t[node]){
            dfs(next);
            pq.push(dp[next]);
        }
        if(pq.empty()) dp[node]=0;
        else if(pq.size()==1) dp[node]=pq.top()+1;
        else{
            while(pq.size()>=2){
                int t1=pq.top();
                pq.pop();
                int t2=pq.top();
                pq.pop();
                pq.push(max(t1,t2)+1);
            }
            dp[node]=pq.top();
        }
    };
    dfs(0);
    cout<<dp[0]<<'\n';

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}