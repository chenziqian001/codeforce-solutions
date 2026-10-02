#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> pre(n+2),suf(n+2);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(i%2==1?1:-1)*a[i];
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+(i%2==1?1:-1)*a[i];
    map<int,int> cnto,cnte;
    cnte[0]=1;
    int res=0;
    for(int i=1;i<=n;i++){
        int same=-suf[i+1];
        int diff=suf[i+1];

        int tgs=k-same;
        int tgd=k-diff;
        if(i%2==0){
            if(cnto.find(tgs)!=cnto.end()) res+=cnto[tgs];
            if(cnte.find(tgd)!=cnte.end()) res+=cnte[tgd];
        }
        else{
            if(cnte.find(tgs)!=cnte.end()) res+=cnte[tgs];
            if(cnto.find(tgd)!=cnto.end()) res+=cnto[tgd];
        }

        if(i%2==1) cnto[pre[i]]++;
        else cnte[pre[i]]++;
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