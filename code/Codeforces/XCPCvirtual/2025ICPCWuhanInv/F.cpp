#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;


int qp(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
int inv(int x){
    return qp(x,mod-2);
}

void solve(){
    int n,m;
    cin>>n>>m;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(mp.find(b)==mp.end()){
            mp[b]=a;
        }
        else mp[b]+=a;
    }
    vector<pair<int,int>> v;
    for(auto [val,cnt]:mp){
        v.push_back({val,cnt});
    }
    sort(v.rbegin(),v.rend());
    n=v.size();
    int k=0,s=0,inf=200000000000000LL,lb=-1;
    bool mx=1;
    for(int i=0;i<n;i++){
        int b=v[i].first,c=v[i].second;
        if(mx){
            int d=(c+m-1)/m;
            k=d%mod*qp(2,b)%mod;
            s=d*m-c;
            lb=b;mx=false;
        }
        else{
            int  gp=lb-b;
            if(s){
                while(gp>0 && s<inf){
                    s=s*2;
                    gp--;
                }
                if(gp>0) s=inf;
            }
            int sp=s-c;
            if(sp<0){
                int  d=(-sp+m-1)/m;
                k=(k+d%mod*qp(2,b)%mod)%mod;
                s=sp+d*m;
            }
         
            else s=min(sp,inf);
            lb=b;
        }
    }
    cout<<k<<'\n';



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


