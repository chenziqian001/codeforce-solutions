
/*
void solve1(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=n;
    int res,resl,resr;
    while(l<=r){
        int mid=(l+r)/2,ll,rr;
        vector<int> big(n+1),pre(n+1);
        for(int i=1;i<=n;i++){
            if(a[i]>=mid) big[i]=1;
            else big[i]=-1;
            pre[i]=pre[i-1]+big[i];
        }
        int mn=inf,flag=0;
        for(int i=k;i<=n;i++){
            if(pre[i-k]<mn) ll=i-k+1;
            mn=min(mn,pre[i-k]);
            if(pre[i]-mn>=0){
                rr=i;
                flag=1;
                break;
            }
        }
        if(flag){
            l=mid+1;
            res=mid;
            resl=ll;
            resr=rr;
        }
        else r=mid-1;
    }

    cout<<res<<" "<<resl<<" "<<resr<<'\n';
}
//----------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

struct tree{
    int n,sz;
    vector<int> t;
    tree(int n):n(n),sz(0),t(n+1,0) {}
    void add(int i,int v){
        for(;i<=n;i+=i&-i){
            t[i]+=v;
            sz+=v;
        }
    }
    int query(int i){
        int res=0;
        for(;i>0;i-=i&-i){
            res+=t[i];
        }
        return res;
    }
    int query(int l,int r){
        return query(r)-query(l-1);
    }
    int kth(int id){
        int pos=0;
        for(int i=1<<18;i>0;i>>=1){
            if(pos+i<=n && t[pos+i]<id){
                id-=t[pos+i];
                pos+=i;
            }
        }
        return pos+1;
    }
    void __clear(){
        fill(t.begin(), t.end(), 0);
    }
    void qmid(int &l, int &r) {
        l = kth((sz + 1) / 2);
        r = kth(sz / 2 + 1);
    }
};
void solve2(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    //取maxmeidan的函数，翻转数组前用一次，翻转后再用一次
    tree t(n);
    auto get_mx=[&]()->tuple<int,int,int>{
        int l=1,r=n;
        int res,resl,resr;
        while(l<=r){
            vector<int> big(n+1);
            vector<int> pre(n+1);
            int mid=(l+r)/2;
            for(int i=1;i<=n;i++){
                if(a[i]>=mid) big[i]=1;
                else big[i]=-1;
                pre[i]=pre[i-1]+big[i];
            }
            int mn=inf,ll,rr;
            int flag=0;
            for(int i=k;i<=n;i++){
                if(pre[i-k]<mn) ll=i-k+1;
                mn=min(mn,pre[i-k]);
                if(pre[i]-mn>=0){
                    flag=1;
                    rr=i;
                    break;
                }
            }
            if(flag){
                res=mid;
                resl=ll;
                resr=rr;
                l=mid+1;
            }
            else r=mid-1;
        }
        return {res,resl,resr};
    };
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) p[i]=i;
    function<int(int)> find=[&](int x){
        if(x!=p[x]){
            p[x]=find(p[x]);
        }
        return p[x];
    };




    map<int,pair<int,int>> mp;
    tuple<int,int,int> mx=get_mx();
    int maxi=get<0>(mx);
    
    int edl=get<1>(mx),edr=get<2>(mx);
    
    mp[maxi]={get<1>(mx),get<2>(mx)};//存入最大median
    for(int i=1;i<=n;i++) a[i]=n-a[i]+1;
    tuple<int,int,int> mi=get_mx();
    int mini=n-get<0>(mi)+1;
    
    int stl=get<1>(mi),str=get<2>(mi);
   
    mp[mini]={get<1>(mi),get<2>(mi)};//存入最小median
    

    auto f=[&]()->void{
        int s = 0, e = 0;
        if(t.sz<=0) return;
        t.qmid(s, e);
        while ((s = find(s)) <= e) {
            if(mp.find(s) != mp.end()) {
                p[s] = s + 1;
                s = find(s);
                continue;
            }
            mp[s] = {stl,str};
            p[s] = s + 1;
        }
        
    };
    t.__clear();
    for(int i=stl;i<=str;i++){
        t.add(a[i],1);
    }
    f();
    while(stl<edl){
        t.add(a[stl++],-1);
        f();
    }
    while(stl>edl){
        t.add(a[--stl],1);
        f();
    }
    while(str>edr){
        t.add(a[str--],-1);
        f();
    }
    while(str<edr){
        t.add(a[++str],1);
        f();
    }
    cout<<mp.size()<<'\n';

    for(auto &m:mp){
        int val=m.first;
        int left=m.second.first;
        int right=m.second.second;
        cout<<val<<" "<<left<<" "<<right<<" "<<'\n';
    }
    
}
signed main(){
    int tt;
    cin>>tt;
    while(tt--) solve2();
    system("pause");
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Seg {
    int l, r, v;
};

// 树状数组
struct BIT {
    vector<int> fw;
    int sz = 0;
    int n;

    BIT(int n) : n(n), fw(n + 1, 0) {}

    void add(int x, int c = 1) {
        sz += c;
        for (; x <= n; x += x & -x) fw[x] += c;
    }

    int kth(int x) {
        int ret = 0;
        for (int k = 18; k >= 0; --k) {
            if ((ret | (1 << k)) <= n && fw[ret | (1 << k)] < x) {
                x -= fw[ret |= 1 << k];
            }
        }
        return ret + 1;
    }

    void qmid(int &l, int &r) {
        l = kth((sz + 1) / 2);
        r = kth(sz / 2 + 1);
    }

    void clear() {
        fill(fw.begin(), fw.end(), 0);
        sz = 0;
    }
};

// 求最大值段
Seg wmax(const vector<int> &a, int n, int m) {
    vector<int> s(n + 1, 0);
    int resl = -1, resr = -1;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        int p = 0;
        bool found = false;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + (a[i] >= mid ? 1 : -1);
            if (i < m) continue;
            if (s[i - m] < s[p]) p = i - m;
            if (s[i] >= s[p]) {
                resl = p + 1;
                resr = i;
                found = true;
                break;
            }
        }
        if (found) l = mid;
        else r = mid - 1;
    }
    return {resl, resr, r};
}

// 并查集查找函数
int find(int x, vector<int> &parent) {
    return x != parent[x] ? parent[x] = find(parent[x], parent) : x;
}

int main() {

    int task;
    cin >> task;
    while (task--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        Seg ed = wmax(a, n, m);

        // 翻转求最小值段
        for (int i = 1; i <= n; ++i) a[i] = n - a[i] + 1;
        Seg bg = wmax(a, n, m);
        bg.v = n - bg.v + 1;
        for (int i = 1; i <= n; ++i) a[i] = n - a[i] + 1;

        // 并查集初始化
        vector<int> parent(n + 2);
        iota(parent.begin(), parent.end(), 0);

        BIT fw(n);
        int l = bg.l, r = bg.r;
        for (int i = l; i <= r; ++i) fw.add(a[i]);

        vector<Seg> res(n + 1);

        auto cover = [&]() {
            int s = 0, t = 0;
            assert(fw.sz > 0);
            fw.qmid(s, t);
            while ((s = find(s, parent)) <= t) {
                res[s] = {l, r, 0};
                parent[s] = s + 1;
            }
        };

        cover();
        while (l > ed.l) fw.add(a[--l]), cover();
        while (r < ed.r) fw.add(a[++r]), cover();
        while (l < ed.l) fw.add(a[l++], -1), cover();
        while (r > ed.r) fw.add(a[r--], -1), cover();
        cover();

        cout << ed.v - bg.v + 1 << "\n";
        for (int v = bg.v; v <= ed.v; ++v) {
            cout << v << " " << res[v].l << " " << res[v].r << "\n";
        }
    }
    system("pause");
    return 0;
}




