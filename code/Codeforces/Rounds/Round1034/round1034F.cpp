#include<iostream>
#include<vector>

using namespace std;
const int N = 2e5 + 5;
vector<int> lpf(N);
vector<int> p(N);
vector<vector<int>> group(N);
void seive(int n) {
    fill(lpf.begin(), lpf.begin() + n + 1, 0);
    for (int i = 2; i <= n; i++) {
        group[i].clear();
        p[i] = 0;
    }
    for (int i = 2;i <= n;i++) {
        if (lpf[i] == 0) {
            for (int j = i;j <= n;j += i) {
                if (lpf[j] == 0) lpf[j] = i;
            }
        }
    }
    for (int i = 2;i <= n;i++) group[lpf[i]].push_back(i);
    for (int i = 2;i <= n;i++) {
        if (!group[i].empty()) {
            vector<int>& g = group[i];
            int m = g.size();
            for (int j = 0;j < m;j++) {
                int from = g[j];
                int to = g[(j + 1) % m];
                p[from] = to;
            }
        }
    }

}



void solve() {
    int n;
    cin >> n;
    seive(n);
    p[1] = 1;
    for (int i = 1;i <= n;i++) {
        cout << p[i] << " ";
    }
    cout << '\n';


}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    system("pause");
    return 0;
}