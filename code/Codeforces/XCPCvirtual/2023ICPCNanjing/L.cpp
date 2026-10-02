#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n,k;
    cin>>n>>k;

    int res=0,rem=0;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        int c,w,f;
        cin>>c>>w>>f;
        a.push_back({f,c*w});
    }
    sort(a.rbegin(),a.rend());
    for(int i=0;i<n;i++){
        if(rem>=a[i].second){
            rem-=a[i].second;
            continue;
        }
        a[i].second-=rem;
        int num=(a[i].second+k-1)/k;
        res+=num*a[i].first;
        rem=num*k-a[i].second;
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
 