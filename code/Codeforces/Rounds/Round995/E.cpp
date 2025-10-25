#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],b[N];
map<int,int> diff;
map<int,int> cnt;
int income;
int n,k;

void solve(){
    cin>>n>>k;
    income=0;
    diff.clear();
    cnt.clear();
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++){
        diff[a[i]+1]++;
        diff[b[i]+1]--;
        cnt[b[i]+1]--;
    }
    int bad=0;
    int tt=n;
    for (auto [x, d] : diff) {
        if (bad <= k) { 
            income = max(income, tt* (x - 1)); 
        }
        bad += d;
        tt+=cnt[x];
    }
    cout<<income<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
