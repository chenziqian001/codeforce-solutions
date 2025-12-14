#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int res=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        res+=(n-i-1)*(i+1);
    }
    set<int> s1,s2;
    s1.insert(-1),s1.insert(n);
    s2.insert(-1),s2.insert(n);
   
    vector<int> idx(n);
    for(int i=0;i<n;i++) idx[i]=i;
    sort(idx.begin(),idx.end(),[&](int &x,int &y){
        return a[x]<a[y];
    });

    for(int i=0;i<n;i++){
        s1.insert(i);
    }

    for(int i=0;i<n;i++){
        int x=idx[i];
        auto it =s1.lower_bound(x);
        it--;
        int z=*it;
        int c=*s1.upper_bound(x);
        if(c!=n){
            int v=*s2.upper_bound(c);
            res-=(x-z)*(v-c);
        }
        s1.erase(x);
        s2.insert(x);
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