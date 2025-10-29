#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
int f[N];
vector<int> g[N];
int col[N],num[N];
int faw,sum_two,sum_more,tt,xor_two;
void init(){
    sum_two=0;
    tt=0;
    sum_more=0;
    faw=0;
    xor_two=0;
    for(int i=1;i<=n;i++){
        g[i].clear();
        num[i]=0;
    }
}

bool check(){
    if(!tt) return false;
    if(sum_more || sum_two>1) return false;
    if(faw>1) return false;
    if(sum_two && col[f[xor_two]]==1) return false;
    return true;
}
void flip(int node){
    col[node]^=1;
    int d=col[node]==1?1:-1;
    tt+=d;
    if(col[f[node]]==0) faw+=d;
    if(num[node]==2) sum_two+=d,xor_two^=node;
    if(num[node]>2) sum_more+=d;
    faw-=d*num[node];
    if(col[node]==1){
        if(col[f[node]]==1 && num[f[node]]==2) sum_two--,sum_more++,xor_two^=f[node];
        num[f[node]]++;
        if(col[f[node]]==1 && num[f[node]]==2) sum_two++,xor_two^=f[node];
    } 
    else{
        if(col[f[node]]==1&&num[f[node]]==2)sum_two--,xor_two^=f[node];
        num[f[node]]--;
        if(col[f[node]]==1&&num[f[node]]==2){
            sum_two++;
            sum_more--;
            xor_two^=f[node];
        }
    }
}


void solve(){
    init();
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>col[i];
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    

    function<void(int,int)> dfs=[&](int node,int fa){
        f[node]=fa;
        if(col[node]==1) tt++;
        int sum=0;
        for(int next:g[node]){
            if(next==fa) continue;
            dfs(next,node);
            if(col[next]==1) sum++;
        }
        if(col[fa]==0 && col[node]==1) faw++;
        if(col[node]==1){
            if(sum==2) sum_two++,xor_two^=node;
            if(sum>2) sum_more++;
        }
        num[node]=sum;
    };
    dfs(1,0);



    while(q--){
        int u;
        cin>>u;
        flip(u);
        if(check()) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}