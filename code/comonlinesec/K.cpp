#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    unordered_map<long long,int> mp;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        mp[x]++;
    }
    int b=0;
    while(mp.find(b)!=mp.end()) b++;
    map<long long,int> vali;
    auto get = [&](long  long x)->int{
        auto it =mp.find(x);
        return it==mp.end()?0LL:it->second;
    };
    for(auto [a,num]:mp){
        int k=a+b;
        int x=0;
        for(;x<n;++x){
            long long y=k-x;
            if(x==y){
                if(get(x)==0) break;
            }
            else{
                int need=(0<=y && y<x)?2:1;
                if(get(x)+get(y)<need){
                    break;
                }
            }
        }
        vali[k]=x;
 
    }
    int q;
    cin>>q;
    long long res=0;
    while(q--){
        int k;
        cin>>k;
        if(vali.find(k)==vali.end()){
            res^=b;
        }
        else res^=vali[k];
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