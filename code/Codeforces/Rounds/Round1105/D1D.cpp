#include <iostream>
using namespace std;

#define int long long

const int mod = 998244353;
const int maxn = 1000005;

int fac[maxn], ifac[maxn];

int qpow(int b, int p) {
    int r = 1;
    b %= mod;
    while (p > 0) {
        if (p % 2 == 1) r = (r * b) % mod;
        b = (b * b) % mod;
        p /= 2;
    }
    return r;
}

void init() {
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    ifac[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 1; i--) {
        ifac[i] = (ifac[i + 1] * (i + 1)) % mod;
    }
}

int comb(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    if (n == m) {
        cout << qpow(n - 1, n) << "\n";
        return;
    }

    int e = 0;
    int lim = n - m;
    
    for (int j = 0; j <= lim; ++j) {
        int t = (comb(lim, j) * qpow(n - 1 - j, n - 1)) % mod;
        if (j % 2 == 1) {
            e = (e - t + mod) % mod;
        } else {
            e = (e + t) % mod;
        }
    }
    
    e = (e * (n - 1)) % mod;
    int ans = (comb(n, m) * e) % mod;
    
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    init();
    int t;
    cin >> t;
    while (t--) solve();
    //system("pause");
    return 0;
}