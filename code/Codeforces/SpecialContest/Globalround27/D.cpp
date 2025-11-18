#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}//快速幂


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<array<int,2>> st;
    int res=0;
    for(int i=0;i<n;i++){
        
        int x=a[i];
        int k=__builtin_ctz(x);
        x>>=k;

        while(!st.empty() && (k>30|| 1LL*x*qp(2,k)>st.back()[0])){
            res= (res-(st.back()[0]*qp(2,st.back()[1])%mod)+mod)%mod;
            res=(res+st.back()[0])%mod;
            k+=st.back()[1];
            st.pop_back();
        }
        st.push_back({x,k});
        res= (res+x*qp(2,k)%mod)%mod;
        cout<<res<<" ";
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