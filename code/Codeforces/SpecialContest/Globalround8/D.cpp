#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> cnt(23);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int j=21;j>=0;j--){
            if(x>>j&1) cnt[j]++;
        }
    }
    int cur=(1LL<<23)-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<23;i++){
        pq.push({cnt[i],i});
    }
    int res=0,last=0;
    while(!pq.empty()){
        auto [num,val]=pq.top();
        int mini=num-last;
        last=num;
        vector<int> tmp;
        while(!pq.empty()&&pq.top().first==num){
            tmp.push_back(pq.top().second);
            pq.pop();
        }
        res+=cur*cur*mini;
        for(int x:tmp){
            cur^=(1<<x);
        }
    }
    cout<<res<<'\n';
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}

