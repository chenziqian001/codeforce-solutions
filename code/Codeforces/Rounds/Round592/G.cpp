#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k;
    cin>>n>>k;
    if(k<n*(n+1)/2){
        cout<<-1<<'\n';
        return;
    }
    int s=n*(n+1)/2;

    int mx=0;
    for(int i=1;i<=n/2;i++) mx+=(n-i+1)-i;
    int d=min(k-s,mx);

    vector<int> p(n+1);
    vector<int> q(n+1);
    iota(p.begin(),p.end(),0);
    iota(q.begin(),q.end(),0);




    cout<<s+d<<'\n';
    for(int i=1;i<=n/2;i++){
        int l=q[i];
        int r=q[n-i+1];
        int del=r-l;
        if(d<del){
            
            swap(q[i],q[i+d]);
            d=0;
            break;
        }
        else{
            swap(q[i],q[n-i+1]);
            d-=del;
        }
    }

    
    for(int i=1;i<=n;i++){
        int x=p[i];
        cout<<x<<" ";
    }
    cout<<'\n';
    for(int i=1;i<=n;i++){
        int x=q[i];
        cout<<x<<" ";
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
    //system("pause");
    return 0;
}