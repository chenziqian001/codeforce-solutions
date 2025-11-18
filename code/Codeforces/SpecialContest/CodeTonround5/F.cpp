#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    vector<int> res(n+1);

    for(int r=0;r<n;r++){
        vector<int> dep(n);
        vector<int> cnt(n+1);
        function<void(int,int)> dfs=[&](int node,int fa){
            cnt[dep[node]]++;
            for(int next:t[node]){
                if(next==fa) continue;
                dep[next]=dep[node]+1;
                dfs(next,node); 
            }
        };
        dfs(r,-1);
        int k=0;
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<cnt[i];j++){
                k++;
                sum+=i;
                res[k]=max(res[k],(n-1)*k-2*sum);
            }
        }
    }

    for(int i=0;i<=n;i++) cout<<res[i]<<" ";
    cout<<'\n';
    //system("pause");
    

}