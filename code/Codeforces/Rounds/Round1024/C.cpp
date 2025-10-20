#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    vector<int> pre(n);
    vector<int> suf(n);
    int now=0;
    for(int i=0;i<n;i++){
        auto it=s.upper_bound(a[i]);
        if(it==s.begin()) continue;
        pre[now]=i;
        now++;
        s.erase(--it);
    }
    s.clear();
    now=0;
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=n-1;i>=0;i--){
        auto it=s.upper_bound(a[i]);
        if(it==s.begin()) continue;
        suf[now]=i;
        now++;
        s.erase(--it);
    }
    long long res=0;
    for(int i=0;i<n;i++){
        if(pre[i]>=suf[i]) break;
        res+=suf[i]-pre[i];
    }
    cout<<res<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
