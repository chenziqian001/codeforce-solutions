#include<bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n;
    cin>>n;
    int  res=0;
    multiset<int> s;

    vector<array<int,3>> a;
    for(int i=0;i<n;i++){
        int k,l,r;
        cin>>k>>l>>r;
        int sum=0;
        vector<int> tmp(k);
        for(int j=0;j<k;j++){
            cin>>tmp[j];
            sum+=tmp[j];
        }
        s.insert(l);

        int pre=0;
        for(int j=0;j<k;j++){
            a.push_back({r-(sum-pre),l+pre,l+pre+tmp[j]});
            pre+=tmp[j];
        }

        a.push_back({r,l+sum,(int)1e9+10});
    }


    sort(a.begin(),a.end());
    for(auto [R,l1,l2]:a){
        res=max(res,R-*s.rbegin());
        s.erase(s.find(l1));
        s.insert(l2);
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