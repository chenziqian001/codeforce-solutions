#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> cnt(n+1);
    int r=-1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>r) r=x;
        if(x>=n+1) continue;
        cnt[x]++;
    }
    int res=1;
    int l=-1;
    
    for(int i=0;i<=n;i++){
        if(cnt[i]!=0) l=i;
        else break;
    }
   
    int pos=-1;
    int mini=2e18;
    for(int i=0;i<=l;i++){
        if(cnt[i]<mini){
            pos=i;
            mini=cnt[i];
        }
    }

    if(pos!=-1){
        if(r>l){
            res+=l+1;
        }
        else{
            res+=mini*(l+1)+pos;
        }
    }
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}