#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int res=0;
    for(int x=0;x<3;x++){
        for(int y=x+1;y<3;y++){
            map<pair<int,int>,int> cnt;
            for(int i=0;i+2<n;i++){
                res+=cnt[{a[i+x],a[i+y]}]++;
            }
        }
    }
    map<tuple<int,int,int>,int> cnt;
    for(int i=0;i+2<n;i++){
        res-=3*cnt[{a[i],a[i+1],a[i+2]}]++;
    }
    cout<<res<<'\n';
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}