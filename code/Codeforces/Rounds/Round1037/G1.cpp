#include<bits/stdc++.h>
using namespace std;
int res;
int n;
void get(vector<int> &a,int m){
    vector<int> c(n+1);
    for(int i=1;i<=n;i++){
        if(a[i]>=m) c[i]=1;
        else c[i]=-1;
    }
    vector<int> sum(n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1];
        sum[i]+=c[i];
    }
    vector<int> sufmx(n+2,-1e9);
    for(int i=n;i>0;i--){
        sufmx[i]=max(sum[i],sufmx[i+1]);
    }
    int premi=0;
    for(int i=1;i<=n;i++){
        if(sufmx[i]>=premi){
            res=max(res,m-a[i]);
        }
        premi=min(premi,sum[i]);
    }
}
void solve(){
    res=-1e9;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> b(a.begin()+1,a.end());
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int x:b) get(a,x);
    cout<<res<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}