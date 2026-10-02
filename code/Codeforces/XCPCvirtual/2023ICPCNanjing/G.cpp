#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int w,v;
    bool operator<(const node& o)const{
        return v>o.v;
    }
};




void solve(){
    int n,W,k;
    cin>>n>>W>>k;
    vector<node> a(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].w>>a[i].v;
        sum+=a[i].v;
    }

    if(k>=n){
        cout<<sum<<'\n';
        return;
    }
    sort(a.begin()+1,a.end());
    vector<vector<int>> suf(n+2,vector<int>(W+1));
    for(int i=n;i>=1;i--){
        for(int j=0;j<=W;j++){
            suf[i][j]=suf[i+1][j];
            if(j>=a[i].w) suf[i][j]=max(suf[i+1][j-a[i].w]+a[i].v,suf[i][j]);
        }
    }

    int res=suf[1][W];
    int prev=0,ext=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=n;i++){
        prev+=a[i].v;
        if(k){
            pq.push(a[i].w);
            if(pq.size()>k){
                ext+=pq.top();
                pq.pop();
            }
        }
        else{
            ext+=a[i].w;
        }
        if(i>=k && ext<=W){
            res=max(res,prev+suf[i+1][W-ext]);
        }
    }
    cout<<res<<'\n';
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
 