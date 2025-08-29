#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        a[i]--;
    }
    vector<vector<int>> pos(n);
    vector<int> id(n);
    vector<int> dp(n+1);
    for(int i=0;i<n;i++){
        id[i]=pos[a[i]].size();
        pos[a[i]].push_back(i);
    }
    for(int i=0;i<n;i++){
        dp[i+1]=dp[i];
        if(id[i]>=a[i]){
            dp[i+1]=max(dp[i+1],a[i]+1+dp[pos[a[i]][id[i]-a[i]]]);
        }
    }
    cout<<dp[n]<<'\n';

}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    system("pause");
    return 0;
}