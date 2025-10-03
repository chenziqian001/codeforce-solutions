#include<bits/stdc++.h>
using namespace std;


void solve(){
    vector<int> nums(2e5+10);
    int n,k;
    cin>>n>>k;
    int l=0,r=n/k+1;
    int res=0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int timer=1;
    auto check=[&](int mid){
        ++timer;
        int cnt=0;
        int cur_mex=0;
        for(int i=0;i<n;i++){
            if(a[i]<=n+1) nums[a[i]]=timer;
            while(nums[cur_mex]==timer) cur_mex++;
            if(cur_mex>=mid){
                cnt++;
                if(cnt >= k) return true;
                cur_mex=0;
                timer++;
            }
            
        }
        
        return cnt>=k;
    };
   
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<res<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}