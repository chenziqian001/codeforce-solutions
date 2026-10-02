#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    vector<int> cnt(3);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    int res=cnt[0];
    int val=min(cnt[1],cnt[2]);
    res+=val;
    cnt[1]-=val;
    cnt[2]-=val;
    res+=cnt[1]/3;
    res+=cnt[2]/3;
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