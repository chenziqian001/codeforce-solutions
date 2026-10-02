#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;



void solve(){
    map<int,int> mp;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    vector<pair<int,int>> a;
    for(auto [val,num]:mp){
        a.push_back({val,num});
    }
    sort(a.begin(),a.end());
    int res=a[0].second,cur=a[0].second;
    int sz=1;
    int m=a.size();
    for(int i=1;i<m;i++){
        if(a[i].first==a[i-1].first+1 && sz<k){
            sz++;
            cur+=a[i].second;
            res=max(res,cur);
        }
        else{
            if(a[i].first!=a[i-1].first+1){
                sz=1;
                cur=a[i].second;
                res=max(res,cur);
            }
            else{
                int pre=i-k;
                cur-=a[pre].second;
                cur+=a[i].second;
                res=max(res,cur);
            }
        }
    }
    res=max(res,cur);
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
