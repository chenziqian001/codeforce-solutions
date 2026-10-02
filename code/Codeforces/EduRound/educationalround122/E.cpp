#include <bits/stdc++.h>

using namespace std;

#define int long long

struct dsu {
    vector<int> fa;
    dsu(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int i) {
        if (fa[i] == i)
            return i;
        return fa[i] = find(fa[i]);
    }
    bool unite(int i, int j) {
        int rooti = find(i);
        int rootj = find(j);
        if (rooti != rootj) {
            fa[rooti] = rootj;
            return true;
        }
        return false;
    }
};

struct edge {
    int u, v;
    int w;
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >>n>>m;

    vector<edge> g(m);
    for (int i = 0; i < m; ++i) {
        cin >> g[i].u >> g[i].v >> g[i].w;
    }

    vector<int> crit;
    crit.push_back(0);
    
    for (int i = 0; i < m; ++i) {
        crit.push_back(g[i].w);
        for (int j = i + 1; j < m; ++j) {
            crit.push_back((g[i].w + g[j].w + 1) / 2);
        }
    }

    sort(crit.begin(), crit.end());
    crit.erase(unique(crit.begin(), crit.end()), crit.end());

    int l = crit.size();
    
    vector<int> slope(l), intercept(l);

    for (int i = 0; i < l; ++i) {
        int x = crit[i];

        sort(g.begin(), g.end(), [x](const edge& e1, const edge& e2) {
            int diff1 = abs(e1.w - x);
            int diff2 = abs(e2.w - x);
            if (diff1 != diff2) return diff1 < diff2;
            return e1.w > e2.w; 
        });

        dsu t(n);
        int curk = 0, curb = 0;
        int edgecount = 0;

        for (const auto& e : g) {
            if (t.unite(e.u, e.v)) {
                edgecount++;
                if (e.w <= x) {
                    curk += 1;
                    curb -= e.w;
                } else {
                    curk -= 1;
                    curb += e.w;
                }
                if (edgecount == n - 1) break;
            }
        }
        slope[i] = curk;
        intercept[i] = curb;
    }

    int p, ktotal, a, bparam, cparam;
    cin >> p >> ktotal >> a >> bparam >> cparam;

    int currentq = 0;
    int ansxor = 0;

    for (int j = 1; j <= ktotal; ++j) {
        if (j <= p) {
            cin >> currentq;
        } else {
            currentq = (currentq * a + bparam) % cparam;
        }

        auto it = upper_bound(crit.begin(), crit.end(), currentq);
        int idx = distance(crit.begin(), it) - 1;

        int cost = slope[idx] * currentq + intercept[idx];
        ansxor ^= cost;
    }

    cout << ansxor << '\n';
    //system("pause");
    return 0;
}