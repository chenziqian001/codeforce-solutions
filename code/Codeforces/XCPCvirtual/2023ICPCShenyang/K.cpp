#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    vector<int> v;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0) v.push_back(a[i]);
    }
    vector<pair<int,int>> qs(q);
    for(int i=0;i<q;i++){
        cin>>qs[i].first>>qs[i].second;
        if(qs[i].second>0) v.push_back(qs[i].second);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int m=v.size();
    vector<int> fw1(m+1),fw2(m+1);
    auto add=[&](int p,int c,int s){
        for(;p<=m;p+=p&-p){
            fw1[p]+=c;
            fw2[p]+=s;
        }
    };

    int sum=0;
    auto ins=[&](int x,int sign){
        if(x<0){
            sum+=sign*x;
        }else if(x>0){
            int p=lower_bound(v.begin(),v.end(),x)-v.begin()+1;
            add(p,sign,sign*x);
        }
    };

    for(int i=1;i<=n;i++){
        ins(a[i],1);
    }
    for(int i=0;i<q;i++){
        int id=qs[i].first;
        int val=qs[i].second;
        ins(a[id],-1);
        a[id]=val;
        ins(a[id],1);
        int pos=0,cc=0,cs=0,tt=-sum;
        for(int j=19;j>=0;j--){
            int nx = pos + (1<<j);
            if(nx<=m && cs+fw2[nx]<=tt){
                cs+=fw2[nx];
                cc+=fw1[nx];
                pos=nx;
            }
        }
        int res=cc;
        if(pos<m) res+=(tt-cs)/v[pos];
        cout<<res+1<<'\n';
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
 
 