#include<bits/stdc++.h>
using namespace std;
#define int long long

struct F{
    int a,b,c,id;
    bool operator<(const F& o)const{
        if(a!=o.a)return a<o.a;
        if(b!=o.b)return b<o.b;
        return c<o.c;
    }
    bool chk(const F& o)const{
        if(a==o.a)return b==o.b;
        return (b-o.b)*(b-o.b)<4*(a-o.a)*(c-o.c);
    }
};


void solve(){
    int n;
    cin>>n;

    vector<F> f(n);
    for(int i=0;i<n;i++){
        cin>>f[i].a>>f[i].b>>f[i].c;
        f[i].id=i;
    }
    sort(f.begin(),f.end());

    vector<int> dp1(n,1),dp2(n,1),res(n);


    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(f[j].chk(f[i])) dp1[i]=max(dp1[i],dp1[j]+1);
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(f[j].chk(f[i]))dp2[i]=max(dp2[i],dp2[j]+1);
        }
    }


    for(int i=0;i<n;i++){
        res[f[i].id]=dp1[i]+dp2[i]-1;
    }

    for(int i=0;i<n;i++){
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
