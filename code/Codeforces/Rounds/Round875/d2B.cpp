#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    vector<int> lena(2*n+1);
    vector<int> lenb(2*n+1);
    int cur=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]) cur++;
        else{
            lena[a[i-1]]=max(lena[a[i-1]],cur);
            cur=1;
        }
    }
    lena[a.back()]=max(lena[a.back()],cur);
    cur=1;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]) cur++;
        else{
            lenb[b[i-1]]=max(lenb[b[i-1]],cur);
            cur=1;
        }
    }
    lenb[b.back()]=max(lenb[b.back()],cur);
    int res=1;
    for(int i=1;i<=2*n;i++){
        res=max(res,lena[i]+lenb[i]);
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