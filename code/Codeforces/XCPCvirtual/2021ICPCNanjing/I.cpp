#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node{
    int x,y,tp;
    bool operator<(const node& o) const{
        return x<o.x;   
    };
};

void solve(){
    int H;
    cin>>H;
    int n;
    cin>>n;
    vector<node> a;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a.push_back({x,y,0});
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        a.push_back({x,y,1});
    }
    sort(a.begin(),a.end());
    map<int,int> f;
    f[0]=0;
    int mod=2*H;
    int res=0;
    for(int i=0;i<a.size();i++){
        int tp=a[i].tp;
        int k1=(a[i].x+a[i].y)%mod;
        int k2=(a[i].x-a[i].y+mod)%mod;
        if(tp==1){
            if(f.count(k1)) f[k1]++;
            if(f.count(k2)) f[k2]++;
        }
        else{
            if(f.count(k1) || f.count(k2)){
                int mx=0;
                if(f.count(k1)) mx=max(mx,f[k1]);
                if(f.count(k2)) mx=max(mx,f[k2]);
                f[k1]=f[k2]=mx;
            }
        }
        if(f.count(k1)) res=max(res,f[k1]);
        if(f.count(k2)) res=max(res,f[k2]);
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
