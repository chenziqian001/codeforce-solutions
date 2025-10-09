#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,l,r;
int cal(vector<int> &a,int k){
    map<int,int> cnt;
    int res=0;
    int lef=0,rig=0;
    while(lef<=rig && rig<n){
        cnt[a[rig]]++;
        while(cnt.size()>k && lef<=rig){
            cnt[a[lef]]--;
            if(!cnt[a[lef]]) cnt.erase(a[lef]);
            lef++;
        }
        int len=rig-lef+1;
        res+=max(0LL,min(r,len)-l+1LL);
        rig++;
    }
    return res;
}


void solve(){
    cin>>n>>k>>l>>r;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=cal(a,k)-cal(a,k-1);
    cout<<ans<<'\n';
    
}


signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}

