#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1e6+5;
int spf[N];
void seive(){
    for(int i=2;i<N;i++) spf[i]=i;
    for(int i=2;i*i<N;i++){
        if(spf[i]==i){
            for(int j=i*i;j<N;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}
vector<int> get(int x){
    vector<int> res;
    while(x>1){
        int p=spf[x];
        res.push_back(p);
        while(x%p==0) x/=p;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    seive();
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> dp;
    for(int i=0;i<n;i++) cin>>a[i];
    seive();
    int res;
    for(int i=0;i<n;i++){
        res=(i==0);
        vector<int> pd=get(a[i]);
        int m=pd.size();
        for(int s=1;s<(1<<m);s++){
            int cnt=0;int y=1;
            for(int j=0;j<m;j++){
                if(1&(s>>j)){
                    cnt++;
                    y=y*pd[j];
                }
            }
            if(cnt&1){
                res=(res+dp[y])%mod;
            }
            else res=(res-dp[y]+mod)%mod;
        }
        for(int s=1;s<(1<<m);s++){
            int y=1;
            for(int j=0;j<m;j++){
                if((s>>j)&1) y*=pd[j];
            }
            dp[y]=(dp[y]+res)%mod;
        }
    }
    cout<<res<<'\n';
    return 0;
}