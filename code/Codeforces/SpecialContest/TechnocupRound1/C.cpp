#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    vector<int> a(6);
    for(int i=0;i<6;i++) cin>>a[i];
    int n;
    cin>>n;
    vector<pair<int,int>> b;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int j=0;j<6;j++){
            b.emplace_back(x-a[j],i);
        }
    }
    sort(b.begin(),b.end());
    vector<int> c(n);
    int res=1e18;
    int cnt=0;

    for(int r=0,l=0;r<b.size();r++){
        if(++c[b[r].second]==1) cnt++;
        while(cnt==n){
            res=min(res,b[r].first-b[l].first);
            if(--c[b[l].second]==0) cnt--;
            l++;
        }
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


