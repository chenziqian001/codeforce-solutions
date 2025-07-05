#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            int x=max(a[n-1],2*a[i]);
            int pos=upper_bound(a.begin(),a.begin()+j,x-a[i]-a[j])-a.begin();
            ans+=j-pos;
        }
    }
    cout<<ans<<'\n';
    return;
    

}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}