#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    const int mx=3000005;

    vector<int>works(n+1); 
    vector<bool>isho(mx,false); 
    vector<vector<int>>nxt(mx,vector<int>(7,-1));
    vector<map<int,int>>root(n+1);

    auto getday=[&](const string&s)->int{
        if(s=="Monday")return 0;
        if(s=="Tuesday")return 1;
        if(s=="Wednesday")return 2;
        if(s=="Thursday")return 3;
        if(s=="Friday")return 4;
        if(s=="Saturday")return 5;
        if(s=="Sunday")return 6;
        return -1;
    };

    for(int i=1;i<=n;i++){
        int t;cin>>t;
        for(int j=0;j<t;j++){
            string s;cin>>s;
            works[i]|=(1<<getday(s));
        }
    }

    for(int i=0;i<m;i++){
        int h;cin>>h;
        if(h<mx) isho[h]=1;
    }

    for(int d=mx-2;d>=0;d--){
        for(int w=0;w<7;w++)nxt[d][w]=nxt[d+1][w];
        if(!isho[d+1]){
            int wnext=d%7; 
            nxt[d][wnext]=d+1;
        }
    }


    auto getnx=[&](int e,int d)->int{
        int res=mx;
        for(int w=0;w<7;w++){
            if((works[e]>>w)&1){
                if(nxt[d][w]!=-1)res=min(res,nxt[d][w]);
            }
        }
        return res;
    };

    auto find=[&](auto&&self,int e,int d)->int{
        if(!root[e].count(d))return d;
        return root[e][d]=self(self,e,root[e][d]);
    };

    for(int i=1;i<=k;i++){
        int p;cin>>p;
        int D=0; 
        for(int j=0;j<p;j++){
            int e;
            cin>>e;
            int cand=getnx(e,D);
            cand=find(find,e,cand);
            root[e][cand]=getnx(e,cand);
            D=cand;
        }
        cout<<D<<(i==k?"":" ");
    }
    cout<<"\n";
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