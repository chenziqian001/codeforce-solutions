#include<bits/stdc++.h>
using namespace std;
#define int long long







void solve(){
    int n,m;
    cin>>n>>m;
    map<pair<int,int>,char> g;
    int c1=0,c2=0;
    while(m--){
        char op;
        cin>>op;
        if(op=='+'){
            int u,v;
            char c;
            cin>>u>>v>>c;
            g[{u,v}]=c;
            if(g.find({v,u})!=g.end()){
                c1++;
                if(g[{v,u}]==c) c2++;
            }
        }
        else if(op=='-'){
            int u,v;
            cin>>u>>v;
            char c=g[{u,v}];
            g.erase({u,v});
            if(g.find({v,u})!=g.end()){
                c1--;
                if(g[{v,u}]==c) c2--;
            }
        }
        else{
            int k;
            cin>>k;
            if(k%2==0){
                if(c2>0){
                    cout<<"YES"<<'\n';
                }
                else cout<<"NO"<<'\n';
            }
            else{
                if(c1>0){
                    cout<<"YES"<<'\n';
                }
                else cout<<"NO"<<'\n';
            }

        }
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