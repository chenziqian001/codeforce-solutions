#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    string ans;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    for(auto &p : mp)
    {
        if(p.second * 2 > n)
        {
            cout << p.first << "\n";
            return;
        }
    }
    cout << "uh-oh\n";

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