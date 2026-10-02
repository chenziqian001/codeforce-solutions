#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int>> cx,cy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int  c;
            cin>>c;
            cx[c].push_back(i);
            cy[c].push_back(j);
        }
    }   
    int res=0;
    for(auto &p:cx){
        auto &x = p.second;
        auto &y = cy[p.first];
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int sumx = x[0], sumy = y[0];
        int sz = x.size();
        for(int j=1;j<sz;j++){
            res += j * x[j] - sumx;
            res += j * y[j] - sumy;
            sumx += x[j];
            sumy += y[j];
        }
    }
    cout<<res*2<<'\n';

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