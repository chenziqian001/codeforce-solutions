#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> b(n);
    for(int i=0;i<n;i++) b[i] =a[i]-i;

    auto check=[&](int t){
        vector<int> mx(n);
        deque<int> dq;
        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front()<i-t) dq.pop_front();
            while(!dq.empty() && b[dq.back()]<=b[i]) dq.pop_back();
            dq.push_back(i);
            mx[i]=b[dq.front()];
        }
        for(int i=0;i<n-k;i++){
            if(i+k+mx[i+k]<=i+mx[i]) return false;
        }
        return true;
    };
    
    int l=0,r=n;
    int res=r;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
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