#include<bits/stdc++.h>
using namespace std;
#define int long long
using u64=uint64_t;

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b=a;

    vector<int> o(q),l(q),r(q),k(q);
    for(int i=0;i<q;i++){
        cin>>o[i]>>l[i]>>r[i];
        l[i]--; 
        if(o[i]==2){
            cin>>k[i];
        }
        b.push_back(r[i]);
    }

    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());

    for(int i=0;i<n;i++) a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin();
    for(int i=0;i<q;i++){
        if(o[i]==1) r[i]=lower_bound(b.begin(),b.end(),r[i])-b.begin();
    }
    
    vector<int> res(q,1);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    int m=b.size();
    
    vector<int> fw(n+1,0);
    auto add=[&](int pos,u64 val){
        for(int i=pos+1;i<=n;i+=i&-i) fw[i]+=val;
    };
    auto query=[&](int pos){
        u64 res=0;
        for(int i=pos;i>0;i-=i&-i) res+=fw[i];
        return res;
    };
    
    auto sum=[&](int L,int R){
        return query(R)-query(L);
    };

    for(int t=0;t<40;t++){
        vector<int> f(m);
        for(int i=0;i<m;i++){
            f[i]=rng()&((1ULL<<40)-1);
        }

        for(int i=0;i<n;i++) add(i,f[a[i]]);
        auto v=a;
        for(int i=0;i<q;i++){
            if(o[i]==1){
                add(l[i],f[r[i]]-f[v[l[i]]]);
                v[l[i]]=r[i];
            }
            else{
                if(res[i]&&sum(l[i],r[i])%k[i]!=0) res[i]=0;
            }
        }
        for(int i=0;i<=n;i++) fw[i]=0;
    }
    
    for(int i=0;i<q;i++){
        if(o[i]==2){
            cout<<(res[i]?"YES":"NO")<<'\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}