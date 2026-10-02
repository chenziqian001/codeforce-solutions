#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    unordered_map<int, vector<int>> mp;
    for (int i = 1; i <= k; i++)
    {
        int b, c;
        cin >> b >> c;
        mp[b].push_back(c);
    }
    vector<int> val;
    for (auto &p : mp)
    {
        auto &vec = p.second;
        sort(vec.rbegin(), vec.rend());
        int sum = 0;
        for (auto num : vec)
        {
            sum += num;
        }
        val.push_back(sum);
    }
    sort(val.rbegin(), val.rend());
    int ans = 0;
    int take = min(n, (int)val.size());
    for (int i = 0; i < take; i++)
    {
        ans += val[i];
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
