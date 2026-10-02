#include<bits/stdc++.h>
using namespace std;
#define int long long

bool check(int m,vector<int>& a){
    vector<int> mis,av;
    vector<int> c(m);

    for(int x:a) if(x<m) c[x]++;
    for(int i=0;i<m;i++){
        if(c[i]) c[i]--;
        else mis.push_back(i);
    }
    for(int x:a){
        if(x<m && c[x]){
            c[x]--;
            av.push_back((x-1)/2);
        }
        else if(x>=m) av.push_back((x-1)/2);
    }
    if(av.size()<mis.size()) return 0;

    sort(av.begin(),av.end());
    int d=av.size()-mis.size();
    for(int i=0;i<mis.size();i++){
        if(av[d+i]<mis[i]) return 0;
    }
    return 1;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int l=0,r=n,ans=0;

    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,a)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}