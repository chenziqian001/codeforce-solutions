#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;


void solve(){
    int n;
    cin>>n;
    vector<int> id(n);
    for(int i=0;i<n;i++){
        int len;
        cin>>len;
        id[--len]=i;
    }
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];
    set<array<int,3>> st;
    st.insert({-1,-1,-1});
    st.insert({n,n,-2});
    int len=0;
    int l=0;
    for(int i=0;i<n;i++){
        if(c[i]!=c[i-1]){
            st.insert({l,len,c[i-1]});
            len=0;
            l=i;
        }
        len++;
    }
    st.insert({l,len,c[n-1]});
    int res=1;
    for(int i=0;i<n;i++){
        int pos=id[i];
        auto it=st.upper_bound({pos,n,n});
        it--;
        auto [l,len,col]=*it;
        res=res*len%mod;
        if(len==1){
            auto [l1,len1,c1]=*prev(it);
            auto [l2,len2,c2]=*next(it);
            if(c1==c2){
                st.erase({l1,len1,c1});
                st.erase({l2,len2,c2});
                st.insert({l1,len1+len2,c1});
            }
        }
        else{
            st.insert({l,len-1,col});
        }
        st.erase({l,len,col});
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