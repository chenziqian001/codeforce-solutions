#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> fw;
int m;

void add(int pos, int val) {
    for (int i = pos; i <= m; i += i & -i) {
        fw[i] = max(fw[i], val);
    }
}

int sum(int pos) {
    int res = -2e18;
    for (int i = pos; i > 0; i -= i & -i) {
        res = max(res, fw[i]);
    }
    return res;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];

    vector<int> b = s;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    m = b.size();

    auto get_pos = [&](int val) {
        return lower_bound(b.begin(), b.end(), val) - b.begin() + 1;
    };

    fw.assign(m + 1, -2e18);
    vector<int> dp(n + 1, -2e18);
    
    dp[0] = 0;
    add(get_pos(s[0]), dp[0] - 0);

    for (int i = 1; i <= n; i++) {
        int val = (a[i - 1] > 0 ? 1 : (a[i - 1] < 0 ? -1 : 0));
        dp[i] = dp[i - 1] + val;
        
        int res = sum(get_pos(s[i]) - 1);
        if (res > -1e18) {
            dp[i] = max(dp[i], i + res);
        }
        
        int cur_pos = get_pos(s[i]);
        add(cur_pos, dp[i] - i);
    }
    cout << dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}