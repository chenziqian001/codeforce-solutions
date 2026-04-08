#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    

    for(int i=0;i<n;i++){
        int lef=0;
        int rig=0;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]) rig++;
            else if (a[j]<a[i]) lef++;
        }
        cout<<max(rig,lef)<<" ";
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
