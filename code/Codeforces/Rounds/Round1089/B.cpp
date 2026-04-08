#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) {
        cin>>p[i];
    }

    set<int> st;
    int cur=0;
    int res=0;
    
    for(int i=1;i<=n;i++){
        while(!st.empty() && *st.begin()<i){
            st.erase(st.begin());
        }
        if(st.empty() || *st.begin()>i){
            cur++;
            if(p[i]>i) st.insert(p[i]);
        }
        else{
            st.erase(st.begin());
            if(p[i]>i) st.insert(p[i]);
        }
        res=max(res,cur);

    }
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
