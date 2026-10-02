#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = stoll(s);
        int len = s.size();
        vector<int> ans;

        for (int i = 1; i <= len; i++) {
            string t = s.substr(len - i) + s.substr(0, len - i);
            int nt = stoll(t);
            int x = nt - n;
            if (x <= 0) continue;
            int md = x % len;
            if (md == 0) md = len;
            string chk = s.substr(len - md) + s.substr(0, len - md);
            int val = stoll(chk);
            if (val == nt) ans.push_back(x);
        }

        sort(ans.begin(), ans.end());
        cout << ans.size();
        for (int v : ans) cout << " " << v;
        cout << "\n";
    }
}