#include<bits\stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int cur=0;
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++){
        if(cur<a[i]) cur++;
        else if(cur>a[i]) cur--;
        pre[i]=max(pre[i-1],cur);
    }
    auto check=[&](int k){
        int g=k;
        for(int i=n;i>=1;i--){
            if(pre[i-1]>=g) return true;
            if(a[i]<g) g++;
            else g--;
        }
        return false;

    };
    int l=0,r=n+1,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}
