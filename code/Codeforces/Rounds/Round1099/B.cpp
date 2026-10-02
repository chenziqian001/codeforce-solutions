#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int mx=-1;
    set<int> st;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            mx=max(mx,a[i-1]-a[i]);
            st.insert(i);
        }
    }
    if(mx==-1){
        cout<<"YES"<<'\n';
        return;
    }


    for(int i=0;i<n;i++){
        if(i && a[i]<a[i-1]){
            cout<<"NO"<<'\n';
            return;
        }
        if(i+1<n && a[i]>a[i+1]){
            a[i+1]+=mx;
        }
    }
    cout<<"YES"<<'\n';
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