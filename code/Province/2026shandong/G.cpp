#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        int c,d;
        cin>>c>>d;
        mp[c].push_back(d);
    }
    int res=0;
    int pf=-2;
    vector<int> pm;
    for(auto [f,v]:mp){
        sort(v.rbegin(),v.rend());
        if(f!=pf+1) pm.clear();
        vector<int> cm;
        for(int i=0;i<v.size();i++){
            int m=(i<pm.size()?pm[i]:0)+1;
            res+=v[i]*m;
            cm.push_back(m);
        }
        pm=cm;
        pf=f;
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

