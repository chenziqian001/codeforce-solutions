#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int l=1;
    int mx=*max_element(a.begin(),a.end());
    for(int i=0;i<n;i++){
        l=lcm(l,a[i]);
        if(l>mx || l>1e9){
            cout<<n<<'\n';
            return;
        }
    }
    map<int,int> cnt;
    for(int i=0;i<n;i++) cnt[a[i]]++;
    auto calc=[&](int d){
        int l=0;
        int c=0;
        for(auto p:cnt){
            if(d%p.first==0){
                if(!l) l=p.first;
                else l=lcm(l,p.first);
                c+=p.second;
            }
        }
        return l==d?c:0;
    
    };
    int res=0;
    for(int i=1;i*i<=mx;i++){
        if(mx%i==0){
            if(!cnt.count(i)) res=max(res,calc(i));
            if(!cnt.count(mx/i)) res=max(res,calc(mx/i));   
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
    return 0;
}