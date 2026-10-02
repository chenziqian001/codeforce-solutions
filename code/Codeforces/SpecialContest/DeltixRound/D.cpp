#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;


void solve(){
    int n,m,p;
    cin>>n>>m>>p;
    int need=(n+1)/2;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    auto begin = std::chrono::steady_clock::now();
    std::mt19937 rnd(begin.time_since_epoch().count());
    int res = 0;
    while ((std::chrono::steady_clock::now() - begin).count() < inf) {
        int id=rnd()%n;
        vector<int> v;
        for(int i=0;i<m;i++){
            if(a[id][i]=='1'){
                v.push_back(i);
            }
        }
        int sz=v.size();
        vector<int> sum(1<<sz);
        for(int i=0;i<n;i++){
            int m=0;
            for(int j=0;j<sz;j++){
                m|=(a[i][v[j]]=='1')<<j;
            }
            sum[m]++;
        }
        for(int i=1;i<(1<<sz);i*=2){
            for(int j=0;j<(1<<sz);j+=2*i){
                for(int k=0;k<i;k++){
                    sum[j+k]+=sum[i+j+k];
                }
            }
        }
        int cur=0;
        for(int i=0;i<(1<<sz);i++){
            if(sum[i]>=need && __builtin_popcount(i)>__builtin_popcount(cur)){
                cur=i;
            } 
        }
        if (__builtin_popcount(cur)>__builtin_popcount(res)) {
            res=0;
            for(int i=0;i<sz;i++) {
                if (cur>>i&1) {
                    res|=1LL<<v[i];
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<(res>>i&1);
    }
    cout<<'\n';
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