#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,q;
    cin>>n>>q;

    string s;
    cin>>s;
    
    vector<pair<int,int>> p(n+1);
    map<pair<int,int>,vector<int>> mp;
    p[0]={0,0};
    mp[{0,0}].push_back(0);
    for(int i=0;i<n;i++){
        p[i+1]=p[i];
        if(s[i]=='U') p[i+1].second++;
        if(s[i]=='D') p[i+1].second--;
        if(s[i]=='L') p[i+1].first--;
        if(s[i]=='R') p[i+1].first++;
        mp[p[i+1]].push_back(i+1);
    }

    auto check=[&](pair<int,int> pt,int l,int r){
        if(!mp.count(pt)) return false;
        auto& v=mp[pt];
        auto it=lower_bound(v.begin(),v.end(),l);
        return it!=v.end()&&*it<=r;
    };
    
    while(q--){
        int x,y,l,r;
        cin>>x>>y>>l>>r;
        pair<int,int> pt={x,y};
        int tx=p[l-1].first+p[r].first-x;
        int ty=p[l-1].second+p[r].second-y;
        if(check(pt,0,l-1)||check(pt,r,n)||check({tx,ty},l-1,r)) cout<<"YES\n";
        else cout<<"NO\n";
    }

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