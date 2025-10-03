#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+10;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    vector<int> suff(m);
    int j=n-1;
    for(int i=m-1;i>=0;i--){
        while(j>=0 && a[j]<b[i]) j--;
        suff[i]=j--;
    }
    j=0;
    vector<int> pre(m);
    for(int i=0;i<m;i++){
        while(j<n && a[j]<b[i]) j++;
        pre[i]=j++;
    }
    if(pre[m-1]<n){
        cout<<0<<'\n';
        return;
    }
    int res=inf;
    for(int i=0;i<m;i++){
        int pp=i==0?-1:pre[i-1];
        int sp=i==m-1?n:suff[i+1];
        if(pp<sp){
            res=min(res,b[i]);
        }
    }

    if(res==inf) cout<<-1<<'\n';
    else cout<<res<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}