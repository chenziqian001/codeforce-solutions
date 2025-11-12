#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> dpl(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dpr(n + 2, vector<int>(n + 1, 0));
    for(int l=0;l<n;l++){
        int cnt=0;
        for(int r=l+1;r<=n;r++){
            cnt+=(s[r-1]=='1');
            dpl[r][cnt]=max(dpl[r][cnt],r-l);
            dpr[l][cnt]=max(dpr[l][cnt],r-l);
        }
    }
    for(int r=0;r<=n;r++){
        for(int cnt=0;cnt<=n;cnt++){
            if(r) dpl[r][cnt]=max(dpl[r-1][cnt],dpl[r][cnt]);
            if(cnt) dpl[r][cnt]=max(dpl[r][cnt],dpl[r][cnt-1]);
        }    
    }
    for(int l=n;l>=0;l--){
        for(int cnt=0;cnt<=n;cnt++){
            if(l+1<=n) dpr[l][cnt]=max(dpr[l][cnt],dpr[l+1][cnt]);
            if(cnt) dpr[l][cnt]=max(dpr[l][cnt],dpr[l][cnt-1]);
        }
    }
    vector<int> dplen(n+1,-1e9);
    for(int l=0;l<n;l++){
        int cnt=0;
        for(int r=l;r<=n;r++){
            if(r>l) cnt+=(s[r-1]=='0');
            if(cnt>k) break;
            dplen[r-l]=max(dplen[r-l],max(dpl[l][k-cnt],dpr[r][k-cnt]));
        }
    } 
    vector<int> res(n+1);
    for (int i = 0; i <= n; ++i) {
        for (int a = 1; a <= n; ++a) res[a] = max(res[a], i + dplen[i] * a);
    }
    for (int i = 1; i <= n; ++i) cout << res[i] << ' ';
    cout<<'\n';
    




}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    //system("pause");
    return 0;
}
