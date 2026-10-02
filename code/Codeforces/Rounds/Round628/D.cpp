#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int u,v;
    cin>>u>>v;
    if(u>v||(v-u)%2){
        cout<<-1<<'\n';
        return;
    }
    if(v==0){
        cout<<0<<'\n';
        return;
    }
    vector<int> cnt(64);
    for(int i=0;i<64;i++){
        if(u>>i&1) cnt[i]++;
    }
    int d=v-u;
    for(int i=63;i>=0;i--){
        int num=d/(1LL<<i);
        if(num%2)num--;
        cnt[i]+=num;
        d-=num*(1LL<<i);
    }
    vector<int> res;
    while(true){
        int cur=0;
        bool ok=false;
        for(int i=0;i<64;i++){
            if(cnt[i]){
                cnt[i]--;
                cur|=1LL<<i;
                ok=true;
            }
        }
        if(!ok)break;
        res.push_back(cur);
    }
    cout<<res.size()<<'\n';
    for(int x:res)cout<<x<<" ";
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}