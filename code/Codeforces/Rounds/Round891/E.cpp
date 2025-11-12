#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b(n);
    for(int i=0;i<n;i++) b[i]=i;
    sort(b.begin(),b.end(),[&](int x,int y){
        return a[x]<a[y];
    });
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[b[i-1]];
    vector<int> ans(n);
    for(int i=1;i<=n;i++){
        int res=0;
        res+=1;
        res+=a[b[i-1]]*(i-1)-pre[i-1]+i-1;
        res+=pre[n]-pre[i]-a[b[i-1]]*(n-i)+n-i;
        ans[b[i-1]]=res;
    }
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<'\n';
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

