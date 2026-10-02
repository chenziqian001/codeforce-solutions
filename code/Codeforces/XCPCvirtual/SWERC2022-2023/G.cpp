#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cur = 0, mx = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == 'W') cur++;
    }
    mx = cur;
    for(int i=n;i<2*n-1;i++) {
        if(s[i] == 'W') cur++;
        if(s[i-n] == 'W') cur--;
        mx = max(mx, cur);
    }
    cout << mx << "\n";
    
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}