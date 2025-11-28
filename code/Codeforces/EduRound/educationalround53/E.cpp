#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

struct info{
    int num,sum;
};


int l,r,k;
string ll,rr;
int diff;
vector<vector<info>> memo;
vector<vector<bool>> vis;

int pow10[25];



info dfs(int i,int mask,bool lo,bool hi){
    if(i==rr.size()) return {1,0};
    if(!lo && !hi && vis[i][mask]){
        return memo[i][mask];
    }
    int down=0;
    if(lo && i>=diff){
        down=ll[i-diff]-'0';
    }

    int up=9;
    if(hi) up=rr[i]-'0';
    

    info res{0,0};
    int st=down;
    if(lo && i<diff){
        info sub=dfs(i+1,0,true,false);
        res.num=(res.num+sub.num)%mod;
        res.sum=(res.sum+sub.sum)%mod;
        st=1;
    }
    for(;st<=up;st++){
        int nm=mask|(1<<st);
        if(__builtin_popcount(nm)>k) continue;

        info sub=dfs(i+1,nm,lo && st==down,hi && st==up);
        res.num=(res.num+sub.num)%mod;
        int val=st*pow10[rr.size()-i-1]%mod;
        res.sum=(res.sum+sub.sum+val*sub.num)%mod;
    }

    if(!lo && !hi){
        vis[i][mask]=true;
        memo[i][mask]=res;
    }
    return res;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>l>>r>>k;
    rr=to_string(r);
    ll=to_string(l);
    diff=rr.size()-ll.size();
    memo.assign(rr.size(),vector<info>(1<<10,{-1,-1}));
    vis.assign(rr.size(),vector<bool>(1<<10,false));

    pow10[0]=1;
    for(int i=1;i<25;i++) pow10[i]=pow10[i-1]*10%mod;
    cout<<dfs(0,0,true,true).sum<<'\n';

    //system("pause");
    return 0;
}
