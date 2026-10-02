#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> col(n+1,0);
    vector<int> u,v;
    bool isb=true;

    auto dfs=[&](auto&& self,int x,int c)->void{
        col[x]=c;
        if(c==1) u.push_back(x);
        else v.push_back(x);
        for(int y:g[x]){
            if(!col[y]) self(self,y,3-c);
            else if(col[y]==c) isb=false;
        }
    };
    dfs(dfs,1,1);
    if(!isb){
        cout<<"Alice"<<'\n';
        for(int i=0;i<n;i++){
            cout<<"1 2"<<endl;
            int node,c;
            cin>>node>>c;

        }
    }
    else{
        cout<<"Bob"<<endl;
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            if((a==1||b==1) && !u.empty()){
                cout<<u.back()<<" "<<1<<endl;
                u.pop_back();
            }else if((a==2||b==2) && !v.empty()){
                cout<<v.back()<<" "<<2<<endl;
                v.pop_back();
            }else{
                if(u.empty()){
                    cout<<v.back()<<" "<<(a==3?a:b)<<endl;
                    v.pop_back();
                }else{
                    cout<<u.back()<<" "<<(a==3?a:b)<<endl;
                    u.pop_back();
                }
            }
        }
    }
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


