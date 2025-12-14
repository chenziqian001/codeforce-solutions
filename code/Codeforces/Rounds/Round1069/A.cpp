#include <bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> cnt(2000);
    int diff=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
        if(!cnt[x]){
            cnt[x]++;
            diff++;
        }
    }
    
    while(!cnt[diff]){
        cnt[diff]++;
        diff++;
    }
    cout<<diff<<'\n';




   
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