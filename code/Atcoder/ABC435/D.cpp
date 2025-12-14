#include<bits/stdc++.h>
using namespace std;





int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[v].push_back(u);
    }

    vector<bool> a(n+1,false);
    function<void(int)> col=[&](int node){
        if(a[node]) return;
        a[node]=true;
        for(int next:g[node]){
            col(next);
        }
    };



    int q;
    cin>>q;
    while(q--){
        int op,v;
        cin>>op>>v;
        if(op==1){
            if(!a[v]){
                col(v);
            }
            else continue;
        }
        else{
            if(a[v]){
                cout<<"Yes"<<'\n';
            }
            else{
                cout<<"No"<<'\n';
            }

        }
        
    }




    system("pause");
}