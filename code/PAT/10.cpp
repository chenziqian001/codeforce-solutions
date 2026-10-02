#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]={x,i+1};
    }
    
    sort(a.begin(),a.end(),[&](pair<int,int> x,pair<int,int> y){
        if(x.first!=y.first){
            return x.first<y.first;
        }
        else return x.second<y.second;
    });
    
    
    vector<int> res;
    res.push_back(a[n-1].second);
    for(int i=n-2;i>=0;i--){
        if(a[i].first==a[n-1].first){
            res.push_back(a[i].second);
        }
        else break;
    }
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i!=res.size()-1){
            cout<<" ";
        }
    }
    cout<<'\n';
    
    int m;
    cin>>m;
    while(m--){
        int val;
        cin>>val;
        pair<int,int> p={val,n+1};
        auto it = upper_bound(a.begin(),a.end(),p);
        if(it==a.end()){
            cout<<0<<'\n';
        }
        else{
            cout<<a[it-a.begin()].second<<'\n';
        }
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