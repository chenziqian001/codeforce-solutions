#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    
    vector<int> pref(n + 2, -INF), suf(n + 2, -INF), dpvl(n + 2, -INF);
    pref[0] = 0;
    
    for(int i=1;i<=n;i++) {
        int c = suf[i];
        int st = i - a[i] + 1;
        
        if(st >= 1) {
            c = max(c, dpvl[st]);
            c = max(c, pref[st - 1]);
        }
        c++;
        
        pref[i] = max(pref[i - 1], c);
        suf[i] = max(suf[i], suf[i - 1]);
        
        if(st >= 1) dpvl[st] = max(dpvl[st], c);
        
        int ed = st + m - 1;
        if(ed <= n && ed >= 1) suf[ed] = max(suf[ed], c);
    }
    
    cout << n - max(0LL, max(pref[n], suf[n])) << "\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}