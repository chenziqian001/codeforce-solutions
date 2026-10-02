#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int inf=2e18;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int res1=0;
    for(int i=0;i<n;i++){
        if(a[i]<b[i]){
            res1=mod;
        }
        else{
            res1+=a[i]-b[i];
        }
    }
    int res2=k;
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        if(b[i]>a[i]){
            cout<<-1<<'\n';
            return;
        }
        else{
            res2+=a[i]-b[i];
        }
    }
    cout<<min(res1,res2)<<'\n';
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