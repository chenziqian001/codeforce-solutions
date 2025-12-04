#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    vector<int> deg(n);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    vector<bool> cyc(n,true);
    queue<int> q;
    for(int i=0;i<n;i++){
        if(deg[i]==1) q.push(i);
    } 
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cyc[node]=false;
        for(int next:t[node]){
            if(deg[next] && --deg[next]==1){
                q.push(next);
            }
        }
    }//拓扑把环给找出来,cyc[node]==true就代表这人是环的一部分了
    
    vector<int> a;
    vector<bool> vis(n,false);
    function<void(int)> dfs1=[&](int node){
        a.push_back(node);
        vis[node]=true;
        for(int next:t[node]){
            if(!vis[next] && cyc[next]){
                dfs1(next);
            }
        }
    };
    
    dfs1(find(cyc.begin(),cyc.end(),true)-cyc.begin());
    //把环分离进a
    //从这里我们开始想象整个图就是由一个环和一颗颗挂在环上的小树组成的
    int m=a.size();
    vector<int> pos(n,-1);
    for(int i=0;i<m;i++){
        pos[a[i]]=i;
    }//给环上每一个点打上一个单独的标记用于区分以换上这个点为根的小树
    vector<int> dep(n);
    function<void(int,int)> dfs2=[&](int node,int fa){
        for(int next:t[node]){
            if(next!=fa && !cyc[next]){
                pos[next]=pos[node];
                dep[next]=dep[node]+1;
                dfs2(next,node);
            }
        }
    };
    for(int i=0;i<m;i++){
        dfs2(a[i],-1);
    }//这里我们一步到位，给每棵小树打上和它们的根节点相同的pos标记，并标记了它们到根节点的距离
    double res=0;
    function<void(int,int,int)> dfs3=[&](int node,int fa,int d){
        res+=1./d;
        for(int next:t[node]){
            if(next==fa || pos[next]!=pos[node]) continue;
            dfs3(next,node,d+1);
        }
    };
    for(int i=0;i<n;i++) dfs3(i,-1,1); //计算小树内的点对贡献

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(pos[i]==pos[j]) continue;
            int dis=abs(pos[i]-pos[j]);
            res+=1./(dep[i]+dep[j]+dis+1);
            res+=1./(dep[i]+dep[j]+m-dis+1);
            res-=1./(dep[i]+dep[j]+m);
        }
    }
    cout << fixed << setprecision(10)<<res<<'\n';

    system("pause");
    
    return 0;    
}