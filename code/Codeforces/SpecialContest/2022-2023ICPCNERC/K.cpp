#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,k;
    cin>>n>>k;
    if(n==1 && k==1){
        cout<<"YES"<<'\n';
        cout<<0<<'\n';
        return;
    }

    if(k>=n){
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
    vector<int> x(n+1);
    int val=1;
    for(int i=1;i<=k;i++){
        x[n-i+1]=val;
        val^=1;
    }

    for(int i=2;i<=n-k+1;i++){
        x[i]=x[n-k+1];
    }
    vector<pair<int,int>> res;
    for(int i=2;i<=n;i++){
        if(x[i]){
            for(int j=1;j<i;j++){
                res.push_back({i,j});
            }
        }
    }

    cout<<res.size()<<'\n';
    for(auto [x,y]:res){
        cout<<x<<" "<<y<<'\n';
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