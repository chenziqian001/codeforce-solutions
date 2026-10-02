#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];

    vector<int> st;
    vector<pair<int,int>> res;
    for(int i=0;i<n;i++){
        int u=p[i];
        int mn=u;
        while(!st.empty() && u>st.back()){
            res.push_back({u,st.back()});
            mn=min(mn,st.back());
            st.pop_back();
        }
        st.push_back(mn);
    }
    if(st.size()==1){
        cout<<"YES"<<'\n';
        //for(auto [u,v]:res){
        //    cout<<u<<" "<<v<<'\n';
        //}
    }
    else cout<<"NO"<<'\n';
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