#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int a,b;
    cin>>a>>b;
    int x=min(a,b);
    int d=abs(a-b);
    vector<int> p;
    int tmp=d;
    for(int i=2;i*i<=tmp;i++){
        if(tmp%i==0){
            p.push_back(i);
            while(tmp%i==0) tmp/=i;
        }
    }
    if(tmp>1) p.push_back(tmp);
    map<pair<int,int>,int> mp;
    function<int(int,int)> dfs=[&](int x,int d){
        if(x<=1) return 1-x;
        if(mp.count({x,d})) return mp[{x,d}];
        int res=x-1;
        for(int v:p){
            if(d%v!=0) continue;
            res=min(res,x%v+1+dfs(x/v,d/v));
            if(x%v!=0){
                res=min(res,v-x%v+1+dfs(x/v+1,d/v));
            }
        }
        return mp[{x,d}]=res;
    };
    cout<<dfs(x,d)<<'\n';
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
