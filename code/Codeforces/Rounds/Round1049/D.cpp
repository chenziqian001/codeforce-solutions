#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    vector<int> b(n);
    int rsum=0;
    int res=0;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        b[i]=a[i].first+a[i].second;
        res+=a[i].second-a[i].first;
        rsum+=a[i].second;
    }
    sort(b.begin(),b.end());
    vector<int> pb(n+1);
    for(int i=1;i<=n;i++){
        pb[i]=pb[i-1]+b[i-1];
    }
    if(n%2==0){
        cout<<res+rsum-pb[n/2]<<'\n';
        return;
    }
    else{
        int tmp=0;
        for(int i=0;i<n;i++){
            int x=a[i].first,y=a[i].second;
            if(x+y>b[n/2-1]){
                tmp=max(tmp,rsum-y-pb[n/2]);
            }
            else{
                tmp=max(tmp,rsum-y-pb[n/2]+(x+y)-b[n/2]);
            }
        }
        cout<<res+tmp<<'\n';
    }
  
}



signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;

}