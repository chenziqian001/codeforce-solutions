#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long



void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) cin>>p[i];
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++){
        if(i>1) pre[p[i]]=p[i-1];
    }
    pre[p[1]]=p[n];
    vector<int> a(m+1);
    vector<int> last(n+1);
    vector<vector<int>> f(m+1,vector<int>(20));
    vector<int> mx(m+1);
    for(int i=1;i<=m;i++){
        cin>>a[i];
        f[i][0]=last[pre[a[i]]];
        last[a[i]]=i;

        for(int j=1;j<20;j++) f[i][j]=f[f[i][j-1]][j-1];
        int cur=i,st=n-1;
        for(int j=19;j>=0;j--){
            if(st>>j&1) cur=f[cur][j];
        }
        mx[i]=max(mx[i-1],cur);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<(mx[r]>=l?'1':'0');
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}