#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef unsigned __int128 u128;

int popcount(u128 x) {
    return __builtin_popcountll((uint64_t)x) + __builtin_popcountll((uint64_t)(x >> 64));
}

void print(u128 x) {
    if (x == 0) { cout << 0 << '\n'; return; }
    string s;
    while (x > 0) { s += (char)('0' + (x % 10)); x /= 10; }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    u128 M = 1, R = 0;
    for (int i = 0; i < n - 1; i++) {
        int k = a[i] - a[i + 1] + 1;
        if (k < 0) { 
            cout << -1 << '\n'; 
            return; 
        }
        u128 m = (u128)1 << (k + 1);     
        u128 target = ((u128)1 << k) - 1; 
        u128 r = target >= (u128)i ? (target - i) % m : (m - (i - target) % m) % m;
        if (M >= m) {
            if (R % m != r) { cout << -1 << '\n'; return; }
        } else {
            if (r % M != R) { cout << -1 << '\n'; return; }
            M = m;
            R = r;
        }
    }
    int pR = popcount(R);
    if (pR > a[0]) { cout << -1 << '\n'; return; } 
    int W = a[0] - pR;
    u128 c = ((u128)1 << W) - 1;
    print(c * M + R);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}