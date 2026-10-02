#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    int p = 63 - __builtin_clzll(n);
    int q = 63 - __builtin_clzll(m);
    
    if(p == q || ((n >> q) & 1)) {
        cout << 1 << '\n' << n << ' ' << m << '\n';
        return;
    }
    
    int k = -1;
    for(int i=q+1;i<p;i++) {
        if((n >> i) & 1) {
            k = i;
            break;
        }
    }
    
    if(k == -1) {
        cout << -1 << '\n';
        return;
    }
    
    int x = n;
    x &= ~(1LL << k);
    int mask = (1LL << k) - 1;
    x &= ~mask;
    x |= (m & mask);
    
    cout << 2 << '\n' << n << ' ' << x << ' ' << m << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}