#include<bits/stdc++.h>
using namespace std;
#define int long long 


bool isp(int x){
    if(x<2) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}
void solve(){
    int a,b,k;
    cin>>a>>b>>k;

    if(!isp(k)){
        cout<<0<<'\n';
        return;
    }
    if(k<60){
        vector<int> p;
        for(int i=0;i<k;i++){
            if(isp(i)) p.push_back(i);
        }

        auto get=[&](int x)->int{
            if(x==0) return 0;
            int res=0;
            auto dfs=[&](auto& self,int id,int val,int f)->void{
                res+=f*(x/val);
                for(int i=id;i<p.size();i++){
                    if(val>(x/p[i])) break;
                    self(self,i+1,val*p[i],-f);
                }
            };
            dfs(dfs,0,1,1);
            return res;
        };
        cout<<get(b/k)-get((a-1)/k)<<'\n';
        return;
    }

    int r=b/k;
    int l=(a-1)/k;

    vector<int32_t> spf(r+1);
    for(int i=1;i<=r;i++) spf[i]=i;
    for(int i=2;i<=r;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=r;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
    int res=0;
    for(int i=l+1;i<=r;i++){
        if(i==1) res++;
        else if(spf[i]>=k) res++;
    }
    cout<<res<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //system("pause");
    return 0;

}