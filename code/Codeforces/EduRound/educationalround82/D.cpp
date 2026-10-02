#include<bits/stdc++.h>
using namespace std;
#define int long long


int get(int x){
    return 63-__builtin_clzll(x);
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> cnt(63);
    int sum=0;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        sum+=x;
        cnt[get(x)]++;
    }
    if(sum<n){
        cout<<-1<<'\n';
        return;
    }
    int res=0;
    for(int i=0;i<63;i++){
        if(n>>i&1){
            if(cnt[i]){
                cnt[i]--;
                cnt[i+1]+=(cnt[i]/2);
                continue;
            }
            int j=i+1;
            while(j<63 && !cnt[j]) j++;
            cnt[j]--;
            res+=j-i;
            for(int k=j-1;k>=i;k--) cnt[k]++;
        }
        else cnt[i+1]+=(cnt[i]/2);
    }
    cout<<res<<'\n';   
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