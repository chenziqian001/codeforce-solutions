#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    map<int,int> ans;
    for(int i=1;i*i<=m;i++){
        if(!(m%i)){
            ans[i]=0;
            ans[m/i]=0;
        }
    }
    for(auto p:ans){
        for(int i=1;i<=n;i++){
            int mod=p.first;
            ans[p.first]+=((a[i]-a[i-1])%mod+mod)%mod;
        }
    }
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int id,val;
            cin>>id>>val;
            for(auto p:ans){
                int mod=p.first;
                ans[p.first]+=((val-a[id-1])%mod+mod)%mod-((a[id]-a[id-1])%mod+mod)%mod;
                if(id<n) ans[p.first]+=((a[id+1]-val)%mod+mod)%mod-((a[id+1]-a[id])%mod+mod)%mod;
                
            }
            a[id]=val;
        }
        else{
            int k;
            cin>>k;
            cout<<(ans[gcd(m,k)]<m?"YES":"NO")<<'\n';
        }
    }
   
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    
    while(t--) solve();
    return 0;
}