#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SegTree {
    int n;
    vector<int> t;
    SegTree(int n) : n(n), t(2 * n, 1e9) {}
    void build(const vector<int>& a) {
        for(int i=0;i<n;i++) t[n+i] = a[i];
        for(int i=n-1;i>0;i--) t[i] = min(t[2*i], t[2*i+1]);
    }
    void update(int p, int v) {
        for(t[p+=n]=v;p>1;p>>=1) t[p>>1] = min(t[p], t[p^1]);
    }
    int query(int l, int r) {
        int res = 1e9;
        for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
            if(l%2==1) res = min(res, t[l++]);
            if(r%2==0) res = min(res, t[r--]);
        }
        return res;
    }
};



void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> pos(n + 1);
    for(int i=0;i<n;i++){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for(int i=0;i<n;i++) cin >> b[i];

    SegTree st(n);
    st.build(a);

    vector<int> ptr(n+1);
    for(int i=0;i<n;i++){
        int x=b[i];
        if(ptr[x]==pos[x].size()){
            cout<<"NO"<<'\n';
            return;
        }
        int idx=pos[x][ptr[x]++];
        if(st.query(0,idx)<x){
            cout<<"NO"<<'\n';
            return;
        }
        st.update(idx,1e9);
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
}