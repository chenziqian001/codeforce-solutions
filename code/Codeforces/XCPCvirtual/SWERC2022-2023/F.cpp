#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> e(m);
    vector<int> deg(n + 1, 0);
    for(int i=0;i<m;i++) {
        cin >> e[i].first >> e[i].second;
        deg[e[i].first]++;
        deg[e[i].second]++;
    }
    int root = -1;
    for(int i=1;i<=n;i++) {
        if(deg[i] < n - 1) {
            root = i;
            break;
        }
    }
    if(root != -1) {
        cout << 2 << "\n";
        for(int i=0;i<m;i++) {
            if(e[i].first == root || e[i].second == root) {
                cout << 1 << " ";
            } else {
                cout << 2 << " ";
            }
        }
        cout << "\n";
    } else {
        cout << 3 << "\n";
        bool first = true;
        for(int i=0;i<m;i++) {
            if(e[i].first == 1 || e[i].second == 1) {
                if(first) {
                    cout << 1 << " ";
                    first = false;
                } else {
                    cout << 2 << " ";
                }
            } else {
                cout<<3<<" ";
            }
        }
        cout<<"\n";
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