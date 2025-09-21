#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    multiset<int> s;
    while(n--){
        int x;
        cin>>x;
        s.insert(x%k);
    }

    auto get=[&](int x){
        auto it=s.lower_bound(k-x);
        return *(it==s.end()?s.begin():it);
    };

    priority_queue<array<int,3>> pq;
    auto x=*s.begin();
    s.erase(s.begin());
    auto y=get(x);
    pq.push({-(x+y)%k,y,x});
    long long res=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int val=p[0],now=p[1],pre=p[2];
        if(!s.count(now)){
            auto nx=get(pre);
            pq.push({-(pre+nx)%k,nx,pre});
            continue;
        }
        res-=val;
        auto it=s.lower_bound(now);
        s.erase(it);
        if(s.empty()) break;
        
        auto nx=get(now);
        pq.push({-(now+nx)%k,nx,now});
        nx=get(pre);
        pq.push({-(nx+pre)%k,nx,pre});
    }
    cout<<res<<'\n';
}


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}