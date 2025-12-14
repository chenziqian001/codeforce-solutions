#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
const int inf=1e9;

int ld[N],rd[N];

struct Node {
    int x, l, r;
    bool operator < (const Node &a) const {
        return r < a.r;
    }
} a[N];

pair<int,int> dp[N];

inline int better(int x, int y) {
    return dp[x].first < dp[y].first ? x : y;
}

inline void relax(int &x, int y) {
    x = better(x, y);
}

struct SegTree {
    int l[N*4], r[N*4], tag[N*4], mx[N*4];

    #define mid ((l[p] + r[p]) >> 1)
    #define ls (p << 1)
    #define rs (p << 1 | 1)

    void build(int p, int pl, int pr) {
        l[p] = pl;
        r[p] = pr;
        tag[p] = mx[p] = n + 1;
        if (pl == pr) return;
        build(ls, pl, mid);
        build(rs, mid + 1, pr);
    }

    inline void push_up(int p) {
        mx[p] = better(mx[ls], mx[rs]);
    }

    inline void push_down(int p) {
        if (tag[p] != n + 1) {
            relax(tag[ls], tag[p]);
            relax(tag[rs], tag[p]);
            tag[p] = n + 1;
        }
    }

    void update_point(int p, int pos, int v) {
        if (l[p] == r[p]) {
            relax(mx[p], v);
            return;
        }
        if (pos <= mid) update_point(ls, pos, v);
        else update_point(rs, pos, v);
        push_up(p);
    }

    void update_range(int p, int ql, int qr, int v) {
        if (ql <= l[p] && r[p] <= qr) {
            relax(tag[p], v);
            return;
        }
        push_down(p);
        if (ql <= mid) update_range(ls, ql, qr, v);
        if (mid < qr) update_range(rs, ql, qr, v);
    }

    int query_range(int p, int ql, int qr) {
        if (ql <= l[p] && r[p] <= qr) return mx[p];
        if (qr <= mid) return query_range(ls, ql, qr);
        if (mid < ql) return query_range(rs, ql, qr);
        return better(query_range(ls, ql, qr),
                      query_range(rs, ql, qr));
    }

    int query_point(int p, int pos) {
        if (l[p] == r[p]) return tag[p];
        push_down(p);
        if (pos <= mid) return query_point(ls, pos);
        return query_point(rs, pos);
    }
} T;


vector<int> g[N];
int deg[N];
int order[N],cnt;
queue<int> q;

void add_e(int u,int v){
    g[u].push_back(v);
    deg[v]++;
}

void tryp(int u){
    if(deg[u]==0){
        q.push(u);
        deg[u]=-1;
        cout<<u<<" ";
    }
}
void topo(){
    for(int i=1;i<=cnt;i++) tryp(order[i]);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:g[u]){
            if(--deg[v]==0){
                tryp(v);
            }
        }
    }
}

void init(){
    T.build(1,0,n+1);
    dp[n+1]={inf,0};
    cnt=0;
    for(int i=1;i<=n;i++){
        g[i].clear();
        deg[i]=0;
    }
}


void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        ld[i]=max(1,i-x+1);
        rd[i]=min(n,i+x-1);
        a[i]={i,ld[i],rd[i]};
    }

    sort(a+1,a+1+n);
    init();

    T.update_point(1,0,0);
    T.update_range(1,0,1,0);

    for(int k=1;k<=n;k++){
        int i=a[k].x;
        dp[i]={inf,0};
        if(ld[i]>rd[i]) continue;


        dp[i].second=better(T.query_point(1,ld[i]),T.query_range(1,ld[i]-1,i-1));
        dp[i].first=dp[dp[i].second].first+1;

        T.update_point(1,rd[i],i);
        T.update_range(1,i+1,rd[i]+1,i);
    }

    int ans=n+1;
    for(int i=n;i>=1;i--){
        if(rd[i]>=n){
            relax(ans,i);
        }
    }

    if(dp[ans].first==inf){
        cout<<-1<<'\n';
        return;
    }


    cout<<dp[ans].first<<'\n';

    for(int i=ans,v;;i=v){
        order[++cnt]=i;
        v=dp[i].second;
        if(!v) break;
        if(ld[i]<=v) add_e(v,i);
        else add_e(i,v);
    }

    topo();
    cout<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}