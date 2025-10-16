#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
vector<int> get(vector<int> a){
    vector<int> res;
    for(int x:a){
        if(res.empty() || x>res.back()) res.push_back(x);
    }
    return res;
}
struct segtree{
    int n;
    vector<int> f,t;
    
    int get_val(int id,int pos){
        return t[pos]*qp(2,f[id])%mod;
    }
    void push(int id){
        if(f[id]){
            f[id*2+1]+=f[id];
            f[id*2+2]+=f[id];
            f[id]=0;
        }
    }
    void resolve(int id,int pos){
        if(f[id]){
            t[pos]=t[pos]*qp(2,f[id])%mod;
            f[id]=0;
        }
    }
    int get(int id,int l,int r,int pos){
        if(l==r-1) return get_val(id,pos);
        push(id);
        int mid=(l+r)/2;
        if(pos<mid) return get(id*2+1,l,mid,pos);
        else return get(id*2+2,mid,r,pos);
    }
    int get(int pos){ return get(0,0,n,pos); }

    void inc(int id,int l,int r,int pos,int val){
        if(l==r-1){
            resolve(id,pos);
            t[pos]=(t[pos]+val)%mod;
            return;
        }
        push(id);
        int mid=(l+r)/2;
        if(pos<mid) inc(id*2+1,l,mid,pos,val);
        else inc(id*2+2,mid,r,pos,val);
    }
    void inc(int pos,int val){ inc(0,0,n,pos,val); }
    void mul2(int id,int l,int r,int ql,int qr){
        if(ql>=qr) return;
        if(ql==l && r==qr){
            f[id]++;
            return;
        }
        push(id);
        int mid=(l+r)/2;
        mul2(id*2+1,l,mid,ql,min(qr,mid));
        mul2(id*2+2,mid,r,max(ql,mid),qr);
    }
    void mul2(int ql,int qr){ mul2(0,0,n,ql,qr); }

    segtree(int n=0){
        this->n=n;
        f.assign(4*n+5,0);
        t.assign(4*n+5,0);
    }
};

vector<int> calc(vector<int> a,vector<int> b){
    int n=a.size(), m=b.size();
    segtree tree(m+1);
    tree.inc(0,1);
    vector<int> res(n,0);
    int maxval=b.back();
    for(int i=0;i<n;i++){
        int x=a[i];
        if(x>maxval) continue;
        if(x==maxval) res[i]=tree.get(m-1);
        int lf=lower_bound(b.begin(),b.end(),x)-b.begin();
        tree.mul2(lf+1,m+1);
        if(b[lf]==x){
            int cur=tree.get(lf);
            tree.inc(lf+1,cur);
        }
    }
    return res;
}

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> ra=a;
    reverse(ra.begin(),ra.end());
    auto lv=get(a);
    auto rv=get(ra);
    auto dpl=calc(a,lv);
    auto dpr=calc(ra,rv);
    reverse(dpr.begin(),dpr.end());
    int mxv=*max_element(a.begin(),a.end());
    int ans=0, pre=0;
    for(int i=0;i<n;i++){
        if(a[i]==mxv) ans=(ans+(pre+dpl[i])%mod*dpr[i])%mod;
        pre=pre*2%mod;
        if(a[i]==mxv) pre=(pre+dpl[i])%mod;
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}



