#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n,y;
    cin>>n>>y;
    vector<long long> cnt(4e5+10);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    } 
    for(int i=1;i<4e5+10;i++){
        cnt[i]+=cnt[i-1];
    }
    long long res=-1e18;
    for(int i=2;i<2e5+10;i++){
        long long f=-y*n;
        for(int j=1;j<4e5/i;j++){
            f+=j*(cnt[j*i]-cnt[j*i-i]);
            f+=min(cnt[j*i]-cnt[j*i-i],cnt[j]-cnt[j-1])*y;
        }
        res=max(res,f);
    }
    cout<<res<<'\n';
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}