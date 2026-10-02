#include<bits/stdc++.h>
using namespace std;
#define int long long

struct SegTree {
    int n;
    vector<int> mn, add;
    SegTree(int n, vector<int>& P) : n(n), mn(4*n+5, 0), add(4*n+5, 0) {
        build(1, 1, n, P);
    }
    void pushup(int u) { mn[u] = min(mn[u<<1], mn[u<<1|1]); }
    void pushdown(int u) {
        if(add[u]) {
            mn[u<<1] += add[u]; add[u<<1] += add[u];
            mn[u<<1|1] += add[u]; add[u<<1|1] += add[u];
            add[u] = 0;
        }
    }
    void build(int u, int l, int r, vector<int>& P) {
        if(l==r) { mn[u] = P[l]; return; }
        int mid = (l+r)>>1;
        build(u<<1, l, mid, P);
        build(u<<1|1, mid+1, r, P);
        pushup(u);
    }
    void update(int u, int l, int r, int ql, int qr, int val) {
        if(ql<=l && r<=qr) { mn[u]+=val; add[u]+=val; return; }
        pushdown(u);
        int mid = (l+r)>>1;
        if(ql<=mid) update(u<<1, l, mid, ql, qr, val);
        if(qr>mid) update(u<<1|1, mid+1, r, ql, qr, val);
        pushup(u);
    }
    // 查找区间 [ql, qr] 内第一个值为 0 (或<=0) 的位置
    int query_zero(int u, int l, int r, int ql, int qr) {
        if(ql>qr) return -1;
        if(ql<=l && r<=qr) {
            if(mn[u]>0) return -1; // 区间内没有0，说明货源充足
            if(l==r) return l;     // 找到了首个归零点
            pushdown(u);
            int mid = (l+r)>>1;
            // 优先查左子树保证找到的是"第一个"
            if(mn[u<<1]<=0) return query_zero(u<<1, l, mid, ql, qr);
            return query_zero(u<<1|1, mid+1, r, ql, qr);
        }
        pushdown(u);
        int mid = (l+r)>>1, res = -1;
        if(ql<=mid) res = query_zero(u<<1, l, mid, ql, qr);
        if(res!=-1) return res;
        if(qr>mid) return query_zero(u<<1|1, mid+1, r, ql, qr);
        return -1;
    }
};
void solve(){
    int n,a;
    cin>>n>>a;
    int base=0;
    vector<int> v(n+1),p(n+1);
    vector<pair<int,int>> sells;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++){
        p[i]=p[i-1];
        if(v[i]<=a){
            p[i]++;
            base+=v[n]-v[i];
        }
        else{
            sells.push_back({v[i],i});
        }

    }
    int m;
    cin>>m;
    vector<pair<int,int>> q(m);
    for(int i=0;i<m;i++){
        cin>>q[i].first;
        q[i].second=i;
    }
    sort(q.rbegin(),q.rend());
    sort(sells.begin(),sells.end());
    SegTree st(n,p);
    set<int> s;
    int cur=base;
    vector<int> res(m);

    for(int i=0;i<m;i++){
        int b=q[i].first;
        int id=q[i].second;
        while(!sells.empty() && sells.back().first>=b){
            int idx=sells.back().second;
            int val=sells.back().first;
            sells.pop_back();
            int pos=st.query_zero(1,1,n,idx,n);
            if(pos==-1){
                st.update(1,1,n,idx,n,-1);
                s.insert(idx);
                cur+=val-v[n];
            }
            else{
                auto it = s.upper_bound(pos);
                if(it!=s.begin()){
                    int z=*prev(it);
                    if(z>idx){
                        s.erase(z);
                        s.insert(idx);
                        st.update(1,1,n,idx,z-1,-1);
                        cur+=val-v[z];
                    }
                }

            }


        }
        res[id]=cur;
    }
    for(int i=0;i<m;i++){
        cout<<res[i]<<" ";
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