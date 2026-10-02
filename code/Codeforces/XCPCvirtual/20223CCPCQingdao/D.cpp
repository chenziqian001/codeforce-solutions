#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node {
    int a, b, w, id;
    bool operator<(const node& o) const {
        return a < o.a;
    }
};
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> W(n + 2, 0);
    for(int i=1;i<=m;i++) {
        int r, w;
        cin >> r >> w;
        W[r] += w;
    }
    for(int i=n;i>=1;i--) W[i] += W[i+1];
    vector<node> v(n + 1);
    for(int i=1;i<=n;i++) v[i] = {a[i], a[i] - W[i], W[i], i};
    sort(v.begin() + 1, v.end());
    vector<int> pref(n + 1, 0), mn_w(n + 1, 2e18), mn_b(n + 2, 2e18);
    for(int i=1;i<=n;i++) {
        pref[i] = pref[i-1] + v[i].a;
        mn_w[i] = min(mn_w[i-1], -v[i].w);
    }
    for(int i=n;i>=1;i--) mn_b[i] = min(mn_b[i+1], v[i].b);
    for(int k=1;k<=n;k++) {
        int ans = pref[k] + mn_w[k];
        if(k < n) ans = min(ans, pref[k-1] + mn_b[k+1]);
        cout << ans << " \n"[k == n];
    }



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