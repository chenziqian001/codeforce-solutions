#include<bits/stdc++.h>
using namespace std;
#define int long long

int z(int x){
    return __builtin_ctzll(x);
}
unordered_map<int,unordered_map<int,int>> memo;

int f(int x,int k){
    if(x==0 || k==0) return 0;
    if(memo[x].count(k)) return memo[x][k];

    x>>=z(x);
    if(x==1LL) return k;
    
    int nx=z(x+1);
    int res=max(f((x+1)>>nx,k-1)+nx,f(x>>nx,k)); 
    return memo[x][k]=res;
}


void solve(){
    int n,k;
    cin>>n>>k;

    cout<<f(n,k)<<'\n';

}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int  t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}