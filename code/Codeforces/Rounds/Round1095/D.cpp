#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mi[2]={inf,inf};
    int ma[2]={-inf,-inf};
    for(int i=0;i<n;i++){
        cin>>a[i];
        int gp=a[i]&1;
        mi[gp]=min(mi[gp], a[i]);
        ma[gp]=max(ma[gp], a[i]);
    }

    int mc[2]={-inf,-inf};
    for(int i=0;i<n;i++){
        int gp=a[i]&1;
        if(mc[gp]>a[i]) {
            if(mi[gp^1]>a[i] && ma[gp^1]<mc[gp]) {
                cout<<"NO"<<'\n';
                return;
            }
        }
        mc[gp]=max(mc[gp], a[i]);
    }
    cout<<"YES"<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)  solve();
    //system("pause");
    return 0;
}