#include<bits/stdc++.h>
using namespace std;
#define int long long

int L,R;

struct state{
    int p;
    int lh1,ll1;
    int lh2,ll2;
    bool operator<(const state &other)const{
        if(p!=other.p) return p<other.p;
        if(lh1!=other.lh1) return lh1<other.lh1;
        if(ll1!=other.ll1) return ll1<other.ll1;
        if(lh2!=other.lh2) return lh2<other.lh2;
        if(ll2!=other.ll2) return ll2<other.ll2;
    }
};

map<state,int> mp;

int dfs(int p,bool lh1,bool ll1,bool lh2,bool ll2){
    if(p<0) return 1;
    
    state st={p,lh1,ll1,lh2,ll2};
    if(mp.find(st)!=mp.end()){
        return mp[st];
    }

    int a_high=1;
    if(lh1){
        a_high=((R>>p)&1);
    }

    int a_low=0;
    if(ll1){
        a_low=((L>>p)&1);
    }
    
    int b_high=1;
    if(lh2){
        b_high=((R>>p)&1);
    }

    int b_low=0;
    if(ll2){
        b_low=((L>>p)&1);
    }
    int res=0;

    for(int i=a_low;i<=a_high;i++){
        for(int j=b_low;j<=b_high;j++){
            if(!(i==0 || j==0)) continue;
            bool nlh1=lh1&&(!(i^((R>>p)&1)));
            bool nll1=ll1&&(!(i^((L>>p)&1)));

            bool nlh2=lh2&&(!(j^((R>>p)&1)));
            bool nll2=ll2&&(!(j^((L>>p)&1)));
            
            
            res+=dfs(p-1,nlh1,nll1,nlh2,nll2);
        }

    }
    return mp[st]=res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        mp.clear();
        cin>>L>>R;

        int res=dfs(32,1,1,1,1);

        cout<<res<<'\n';

    }
    
    //system("pause");
    return 0;
}