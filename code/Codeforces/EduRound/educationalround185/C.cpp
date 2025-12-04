#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> q(n);
    vector<int> r(n);
    
    for(int i=0;i<n;i++) cin>>q[i];
    for(int i=0;i<n;i++) {
        cin>>r[i];
    }

    sort(q.begin(),q.end());
    sort(r.begin(),r.end());



    int res=0;
    int up=n;

    for(int i=0;i<n;i++){
        if(up==0) break;
        int need=(k-r[i])/(r[i]+1);

        auto it=upper_bound(q.begin(),q.begin()+up,need)-q.begin()-1;
        if(it>=0){
            res++;
            up=it;
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