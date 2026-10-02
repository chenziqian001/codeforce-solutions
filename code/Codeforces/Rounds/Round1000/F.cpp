#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=600010;
int fac[N],ifac[N],cat[N],icat[N];

int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
} //快速幂

int inv(int x){return qp(x,mod-2);} //逆元

int C(int n,int m){return fac[n]*ifac[m]%mod*ifac[n-m]%mod;} //组合数

void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    ifac[N-1]=inv(fac[N-1]);
    for(int i=N-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
    for(int i=0;i<=N/2;i++){
        cat[i]=C(2*i,i)*inv(i+1)%mod; //预处理卡特兰数
        icat[i]=inv(cat[i]);          //预处理卡特兰数的逆元
    }
}

struct node{
    int l,r,id;
};

void solve(){
    int n;
    cin>>n;
    vector<node> a(n+1);
    a[0]={0,n*2+1,0};
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
    }

    sort(a.begin(),a.end(),[&](node x,node y){
        return x.l==y.l?x.r>y.r:x.l<y.l;
    });

    vector<int> fa(n+1),len(n+1),p(n+1);
    vector<int> st;
    for(int i=0;i<=n;i++){
        while(!st.empty() && a[st.back()].r<a[i].r) st.pop_back();
        if(!st.empty()) fa[a[i].id]=a[st.back()].id;
        st.push_back(i);
        len[a[i].id]=a[i].r-a[i].l-1;
        p[i]=i;
    }

    for(int i=1;i<=n;i++){
        len[fa[a[i].id]]-=(a[i].r-a[i].l+1);
    }

    int res=1;
    for(int i=0;i<=n;i++) res=res*cat[len[i]/2]%mod;
    vector<int> ans(n+1);
    ans[n]=res;
    auto find=[&](auto &&self,int x)->int{
        return x==p[x]?x:p[x]=self(self,p[x]);
    };

    for(int i=n;i>=1;i--){
        int pa=find(find,fa[i]);
        res=res*icat[len[pa]/2]%mod*icat[len[i]/2]%mod;
        len[pa]+=len[i]+2;
        res=res*cat[len[pa]/2]%mod;
        p[i]=pa;
        ans[i-1]=res;
    }


    for(int i=0;i<=n;i++) cout<<ans[i]<<" ";
    cout<<'\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int tt;
    cin>>tt;
    while(tt--) solve();
    //system("pause");
    return 0;
}