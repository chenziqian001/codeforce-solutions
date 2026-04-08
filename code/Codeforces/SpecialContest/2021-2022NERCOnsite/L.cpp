#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,m,s;
    cin>>n>>m>>s;



    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }

    vector<int> col(n+1),fa(n+1);
    queue<int> q;

    for(int v:g[s]){
        col[v]=v;
        fa[v]=s;
        q.push(v);
    }


    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int v:g[u]){
            if(v==s) continue;
            if(!col[v]){
                col[v]=col[u];
                fa[v]=u;
                q.push(v);
            }
            else if(col[v]!=col[u]){
                vector<int> lu1;
                vector<int> lu2;
                int cur=v;
                while(fa[cur]){
                    lu1.push_back(cur);
                    cur=fa[cur];
                }
                lu1.push_back(s);
                reverse(lu1.begin(),lu1.end());
                lu2.push_back(v);
                cur=u;
                while(fa[cur]){
                    lu2.push_back(cur);
                    cur=fa[cur];
                }
                lu2.push_back(s);
                reverse(lu2.begin(),lu2.end());
                cout<<"Possible"<<'\n';
                cout<<lu1.size()<<'\n';
                for(int x:lu1){
                    cout<<x<<" ";
                }
                cout<<'\n';

                cout<<lu2.size()<<'\n';
                for(int x:lu2){
                    cout<<x<<" ";
                }
                cout<<'\n';
                return;
            }
        }
    }
    cout<<"Impossible"<<'\n';
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