#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=-1e18;

struct pa{
    int mx1=0;
    int mx2=0;
};


void upd(pa &p,int val){
    if(val>p.mx1){
        p.mx2=p.mx1;
        p.mx1=val;
    }
    else if(val>p.mx2){
        p.mx2=val;
    }
}

pa merge(pa &p,pa &q){
    pa res=p;
    upd(res,q.mx1);
    upd(res,q.mx2);
    return res;
}

void solve(){
    int n,k;
    cin>>n>>k;

    int bit=log2(n)+1;
    int s=1<<bit;
    vector<pa> f(s);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        upd(f[x],i);
    }
    
    for(int i=0;i<bit;i++){
        for(int j=0;j<s;j++){
            if((j>>i)&1){
                f[j]=merge(f[j],f[j^(1<<i)]);
            }
        }
    }

    int res=inf;
    for(int i=0;i<s;i++){
        if(f[i].mx2>0){
            res=max(res,f[i].mx1*f[i].mx2-k*i);
        }
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