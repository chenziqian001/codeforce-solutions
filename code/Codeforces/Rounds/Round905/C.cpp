#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b=a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());

    for(int i=0;i<n;i++) a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;

    vector<int> sl(n+3,-1);
    for(int i=0;i<n;i++){
        sl[a[i]]=i;
    }
    int suf=0;
    for(int i=0;i<n;i++){
        if(sl[a[i]]==i){
            suf++;
        }
    }
    vector<int> pl(n+3,-1);
    int res=0;
    for(int i=0;i<n;i++){
        if(pl[a[i]]==-1){    
            pl[a[i]]=i;
            res+=suf;
        }
        if(sl[a[i]]==i){ 
            suf--;
        }
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