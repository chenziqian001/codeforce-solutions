#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long N=2e5+10;
const long long inf=1e18;
vector<long long> a(N);
vector<long long> b(N);
vector<long long> ls(N);
vector<long long> rs(N); 
vector<long long> stk(N);
int n,k;

void build(){
    int top=0;
    for(int i=1;i<=n;i++){
        int pos=top;
        while(pos>0 && b[stk[pos]]>b[i]) pos--;
        if(pos>0){
            rs[stk[pos]]=i;
        }
        if(pos<top){
            ls[i]=stk[pos+1];
        }
        stk[++pos]=i;
        top=pos;
    }
}
bool dfs(int l,int r,int x,int fa){
    if(fa && b[x]%b[fa]) return false;
    if(l>=r) return true;
    return dfs(l,x-1,ls[x],x) && dfs(x+1,r,rs[x],x);
}
bool check(long long x){
    for(int i=1;i<=n;i++) b[i]=a[i]+x;
    for(int i=1;i<=n;i++) ls[i]=rs[i]=0;    
    build();
    return dfs(1,n,stk[1],0);
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    long long mini=inf;
    for(int i=1;i<=n;i++) mini=min(mini,a[i]);
    long long g=0;
    for(int i=1;i<n;i++) g=__gcd(g,abs(a[i+1]-a[i]));
    if(g==0){
        cout<<k<<" "<<k*(k+1)/2<<'\n';
        return;
    }
    vector<long long> d;
    for(int i=1;i*i<=g;i++){
        if(g%i==0){
            d.push_back(i);
            if(i*i!=g) d.push_back(g/i);
        }
    }
    long long sum=0;
    int cnt=0;
    for(long long dd:d){
        long long x=dd-mini;
        if(x<1 || x>k) continue;
        if(check(x)){
            sum+=x;
            cnt++;
        }
    }
    cout<<cnt<<" "<<sum<<'\n';
}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}