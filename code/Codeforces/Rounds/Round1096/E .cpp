#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> suf(n+2,inf);
    for(int i=n;i>=1;i--) suf[i]=min(suf[i+1],a[i]);
    int base=0;
    for(int i=n;i>=1;i--) base+=max(a[i]-suf[i+1],0LL);
    int res=base;
    vector<int> st;
    
    for(int i=1;i<=n;i++){
        while(!st.empty()&&a[st.back()]>=a[i]) st.pop_back();
        int L=st.empty()?0:st.back();
        if(a[i]==suf[i]) res=max(res,base+i-L-1);
        st.push_back(i);
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