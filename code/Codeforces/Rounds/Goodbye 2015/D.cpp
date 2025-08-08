#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> lcp(n + 1, vector<int>(n + 1));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }
    }
    vector<vector<int>> f(n, vector<int>(n));
    for (int j = 0; j < n; j++) {
        if (s[0] != '0') {
            f[0][j] = 1; 
        }
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') continue; 

        int preSum = 0;
        for (int j = i, k = i - 1; j < n; j++) {
            f[i][j] = preSum;

            if (k >= 0) {
                int common = lcp[k][i];
                int len=i-k;
                if (common<len && s[k + common] < s[i + common]) {
                    f[i][j] = (f[i][j] + f[k][i - 1]) % M;
                }

                preSum = (preSum + f[k][i - 1]) % M;
                k--;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = (res + f[i][n - 1]) % M;
    }

    cout << res << '\n';
    system("pause");
    return 0;
}
