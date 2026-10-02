#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    vector<int> id(n+1);
    iota(id.begin()+1,id.end(),1);
    sort(id.begin()+1,id.end(),[&](int i,int j){
        return pre[i-1]<pre[j-1];
    });

    vector<int> res(n+1);
    for(int i=1;i<=n;i++){
        res[id[i]]=n-i+1;
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}