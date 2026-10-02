#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
const int mod = 998244353;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=accumulate(a.begin(),a.end(),0LL);
    sort(a.begin(),a.end());
    int mx=a.back();
    a.pop_back();
    n=a.size();
    auto check=[&](int mid)->bool{
        if(mid==0) return true;
        vector<pair<int,int>> f(1<<n);
        for(int m=0;m<(1LL<<n);m++){
            int x=f[m].first,y=f[m].second;
            for(int j=0;j<n;j++){
                if(!(m>>j&1)){
                    int nm=m|(1LL<<j),nx=x,ny=y+a[j];
                    if(ny>=mid){
                        nx++;
                        ny=0;
                    }
                    f[nm]=max(f[nm],{nx,ny});
                }
            }
        }
        return f[(1LL<<n)-1].first>=k;
    };

    int l=0,r=sum;
    int res=l;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    res+=mx;
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
