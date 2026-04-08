#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int r,g,b;
    cin>>r>>g>>b;
    int cnt[3]={r,g,b};
    char col[3]={'R','G','B'};
    string res;
    while(1){
        int x=-1;
        for(int i=0;i<3;i++){
            if(!cnt[i]) continue;
            int n=res.size();
            if(n>=1 && res[n-1]==col[i]) continue;
            if(n>=3 && res[n-3]==col[i]) continue;
            if(x==-1) x=i;
            else if(cnt[i]>cnt[x]) x=i;
            else if(cnt[i]==cnt[x] && n>=2 && res[n-2]==col[i]) x=i;
        }
        if(x==-1) break;
        res+=col[x];
        cnt[x]--;
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


