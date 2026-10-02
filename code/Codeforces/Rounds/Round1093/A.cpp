#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> cnt(101);
    bool ok=true;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        if(cnt[a[i]]>=2){
            ok=false;
        }
    }
    sort(a.rbegin(),a.rend());
    if(!ok){
        cout<<-1<<'\n';
        return;
    }
    for(int x:a){
        cout<<x<<" ";
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