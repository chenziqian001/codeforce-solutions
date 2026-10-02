#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int idx[2525],cnt=0;

int lcm(int a,int b){return a/__gcd(a,b)*b;}

vector<vector<vector<int>>> dp;

void solve(){
    int l,r;
    cin>>l>>r;
    
    auto get=[&](int x){
        int a[20],len=0;
        while(x){a[++len]=x%10;x/=10;}
        auto dfs=[&](auto self,int p,int m,int l,bool lim)->int{
            if(p==0) return m%l==0;
            if(!lim && dp[p][m][idx[l]]!=-1)return dp[p][m][idx[l]];
            int res=0;
            int up=lim?a[p]:9;
            for(int i=0;i<=up;i++)
                res+=self(self,p-1,(m*10+i)%2520,i?lcm(l,i):l,lim&&i==up);
            if(!lim) dp[p][m][idx[l]]=res;
            return res;
        };
        return dfs(dfs,len,0,1,true);
    };
    cout<<get(r)-get(l-1)<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=2520;i++)if(2520%i==0)idx[i]=cnt++;
    dp.assign(20,vector<vector<int>>(2520,vector<int>(50,-1)));
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}