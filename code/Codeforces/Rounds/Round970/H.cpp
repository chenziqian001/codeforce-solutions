#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> cnt(n+1),pre(n+1),res(n+1,-1);

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+cnt[i];
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        if(res[x]!=-1){
            cout<<res[x]<<'\n';
            continue;
        }
        int l=0,r=x-1,ans=x-1;
        while(l<=r){
            int mid=(l+r)/2;
            int tt=0;
            for(int j=0;j<=n;j+=x){
                int R=min(n,j+mid);
                int L=j-1;
                tt+=pre[R]-(L>=0?pre[L]:0);
            }
            if(tt>n/2){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        res[x]=ans;
        cout<<ans<<" ";
    }
    cout<<'\n';






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