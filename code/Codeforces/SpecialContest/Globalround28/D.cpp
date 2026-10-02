#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]=max(a[i],a[0]);
    }
    sort(a.begin(),a.end());    
    vector<int> b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
        if(b[i]<=a[0]) b[i]= inf+1;
    }
    sort(b.rbegin(),b.rend());
    for(int i=0;i<m;i++){
        b[i]=a.end()-lower_bound(a.begin(),a.end(),b[i]);
    }

    for(int k=1;k<=m;k++){
        int res=0;
        for(int i=k-1;i<m;i+=k){
            res+=b[i]+1;
        }
        cout<<res<<" \n"[k==m];
    }
    
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