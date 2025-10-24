#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    deque<pair<int,int>> dq;
    vector<int> vis(n+1);
    int mex=0;
    int sum=0;
    for(int i=0;i<n;i++){
        vis[a[i]]=1;
        while(vis[mex]) mex++;
        dq.push_back({mex,1});
        sum+=mex;
    }
    int res=sum;

    for(int i=0;i<n-1;i++){
        pair<int,int> cur={a[i],0};
        sum-=dq.front().first;
        dq.front().second--;
        if(dq.front().second==0) dq.pop_front();
        while(!dq.empty() && a[i]<=dq.back().first){
            sum-=dq.back().second*dq.back().first;
            cur.second+=dq.back().second;
            dq.pop_back();
        }
        dq.push_back(cur);
        sum+=cur.first*cur.second;
        dq.push_back({n,1});
        sum+=n;
        res=max(res,sum);


    }
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}