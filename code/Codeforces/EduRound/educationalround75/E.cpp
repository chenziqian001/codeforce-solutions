#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n+1);
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        int m,p;
        cin>>m>>p;
        a[m].push_back(p);
    }
    int tt=n;
    int res=0;
    int buy=0;
    for(int i=n;i>=1;i--){

        for(int p:a[i]) pq.push(p);
        tt-=a[i].size();
        while(!pq.empty() && tt+buy<i){
            res+=pq.top();
            pq.pop();
            buy++;
        }
    }
    cout<<res<<'\n';    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}