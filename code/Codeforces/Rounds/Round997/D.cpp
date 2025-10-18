#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int c=0;
    for(int x=1;x<=10;x++){
        vector<int> pre(n+1);
        map<int,int> cnt;
        int l=0;
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+(a[i]<=x?-1:1);
            if(a[i]==x){
                while(l<=i){
                    cnt[pre[l++]]++;
                }
            }
            if(cnt.find(pre[i+1])!=cnt.end()) c+=cnt[pre[i+1]];
        }
    }
    int res=n*(n+1)/2-c;
    cout<<res<<'\n';
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}