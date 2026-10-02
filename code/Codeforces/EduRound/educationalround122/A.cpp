#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    
    if (n % 7 == 0) {
        cout << n << '\n';
        return;
    }
    
    int base = n - (n % 10);
    for (int i = 0; i <= 9; ++i) {
        if ((base + i) % 7 == 0) {
            cout << base + i << '\n';
            return;
        }
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