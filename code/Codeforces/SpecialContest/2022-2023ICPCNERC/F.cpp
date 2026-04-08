#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    if(n==1){
        if(a==b){
            cout<<1<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
        cout<<a<<":"<<b<<'\n';
        return;
    }

    if(a+b<n){
        cout<<n-a-b<<'\n';
        for(int i=0;i<a;i++){
            cout<<1<<":"<<0<<'\n';
        }
        for(int i=0;i<b;i++){
            cout<<0<<":"<<1<<'\n';
        }
        for(int i=0;i<n-a-b;i++){
            cout<<0<<":"<<0<<'\n';
        }
        return;
    }

    cout<<0<<'\n';
    vector<pair<int,int>> res(n);
    for(int i=0;i<n-1;i++){
        if(a){
            res[i].first=1;
            a--;
        }
        else{
            res[i].second=1;
            b--;
        }
    }
    res[n-1]={a,b};
    if(res[n-1].first==res[n-1].second){
        if(res[0].first>0){
            res[0].first++;
            res[n-1].first--;
        }
        else{
            res[0].second++;
            res[n-1].second--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<res[i].first<<":"<<res[i].second<<'\n';    
    }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    
    //system("pause");
    return 0;
}