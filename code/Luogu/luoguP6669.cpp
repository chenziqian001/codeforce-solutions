#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

int bn[60]; int k;
int bm[60];


struct state{
    int pos;
    bool ok,dif,fn,fm;

    bool operator<(const state &other) const{
        if(pos!=other.pos) return pos<other.pos;
        if(ok!=other.ok) return ok<other.ok;
        if(dif!=other.dif) return dif<other.dif;
        if(fm!=other.fm) return fm<other.fm;
        if(fn!=other.fn) return fn<other.fn;
        return false;
    }

};

map<state,int> mp;

int dfs(int pos,bool ok,bool dif,bool fn,bool fm){
    if(pos<0) return ok;
    state st={pos,ok,dif,fn,fm};
    if(mp.find(st)!=mp.end()){
        return mp[st];
    }


    int upn=fn?k-1:bn[pos];
    int upm=fm?k-1:bm[pos];
    int res=0;

    for(int i=0;i<=upn;i++){
        for(int j=0;(dif || j<=i)&&j<=upm;j++){
            res=(res+dfs(pos-1,ok||(i<j),dif || i!=j,fn || (i<upn),fm || (j<upm)))%mod;
        }
    }
    return mp[st]=res;

}


void solve(){
    mp.clear();
    int n,m;
    cin>>n>>m;
    int mx=max(n,m);
    int len=0;
    while(mx){
        mx/=k;
        len++;
    }
    for(int i=0;i<len;i++) bn[i]=n%k,n/=k;
    for(int i=0;i<len;i++) bm[i]=m%k,m/=k;
    for(int i=len;i<60;i++) bn[i]=0;
    for(int i=len;i<60;i++) bm[i]=0;
    cout<<dfs(len-1,false,false,false,false)<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t>>k;
    while(t--) solve();
    //system("pause");
    return 0;
}