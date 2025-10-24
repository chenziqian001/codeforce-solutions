#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=2e5+10;
int p2[N];
struct fw{
    int n;
    vector<int> t;
    fw(int n):n(n),t(n+1,0) {}

    void add(int i,int val){
        val%=mod;
        if(val<0) val+=mod;

        for(;i<=n;i+=i&-i) t[i]=(t[i]+val+mod)%mod;
    }
    int sum(int i){
        int res=0;
        for(;i>=1;i-=i&-i) res=(res+t[i])%mod;
        return res;
    }

    int q(int l,int r){
        return (sum(r)-sum(l-1)+mod)%mod;
    }
};

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    s='x'+s;
    int q;
    cin>>q;
   
    fw pre0(n); //存0
    fw pre1(n);   //存1
    fw suf0(n);
    fw suf1(n);

    int res=(p2[n]-1LL+mod)%mod;
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            if(i) res=(res+pre0.sum(i-1)*p2[n-i]%mod)%mod;
            pre1.add(i,p2[i-1]);
            suf1.add(i,p2[n-i]);
        }
        else{
            if(i) res=(res+pre1.sum(i-1)*p2[n-i]%mod)%mod;
            pre0.add(i,p2[i-1]);
            suf0.add(i,p2[n-i]);
        }
    }


    while(q--){
        int p;
        cin>>p;
        if(s[p]=='1'){
            res=(res-p2[n-p]*pre0.sum(p-1)%mod+mod)%mod;
            res=(res-p2[p-1]*suf0.q(p+1,n)%mod+mod)%mod;
            pre1.add(p,-p2[p-1]);
            suf1.add(p,-p2[n-p]);
            pre0.add(p,p2[p-1]);
            suf0.add(p,p2[n-p]);
            res=(res+pre1.sum(p-1)*p2[n-p]%mod)%mod;
            res=(res+suf1.q(p+1,n)*p2[p-1]%mod)%mod;
            s[p]='0';
        }
        else{
            res=(res-p2[n-p]*pre1.sum(p-1)%mod+mod)%mod;
            res=(res-p2[p-1]*suf1.q(p+1,n)%mod+mod)%mod;
            pre0.add(p,-p2[p-1]);
            suf0.add(p,-p2[n-p]);
            pre1.add(p,p2[p-1]);
            suf1.add(p,p2[n-p]);
            res=(res+pre0.sum(p-1)*p2[n-p]%mod)%mod;
            res=(res+suf0.q(p+1,n)*p2[p-1]%mod)%mod;
            s[p]='1';
        }
        cout<<res<<" ";
    }
    cout<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    p2[0]=1;
    for(int i=1;i<N;i++) p2[i]=p2[i-1]*2%mod;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}