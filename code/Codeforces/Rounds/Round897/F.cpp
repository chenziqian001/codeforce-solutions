#include<bits/stdc++.h>
using namespace std;

const int N=2000005;


map<vector<int>,int> h;  
vector<int> siz;         
vector<vector<int>> nxt; 


vector<int> adj[N];     
int id[N];              
int max_id=0;            
int seed_id=0;           
int ans_sz=0;           

vector<int> a; 
vector<int> b; 
vector<int> c;

int get_id(vector<int>& ch){
    if(h.count(ch)) return h[ch];
    int s=1;
    for(int x:ch) s+=siz[x];
    siz.push_back(s);
    nxt.push_back(ch);
    int new_id=h.size();
    h[ch]=new_id;
    return new_id;
}

void dfs(int u,int fa){
    vector<int> ch;
    for(int v:adj[u]){
        if(v==fa) continue;
        dfs(v,u);
        ch.push_back(id[v]);
    }
    sort(ch.begin(),ch.end());
    id[u]=get_id(ch);
    max_id=max(max_id,id[u]);
}


void solve(int sur,int lst){
    
    if(!sur){
        int k=get_id(b);
        c.push_back(k);
       
        if(k>max_id){
            ans_sz=1;
            seed_id=k;
        }
        return;
    }
    for(int i=lst;i<a.size();i++){
        if(siz[a[i]]<=sur){
            b.push_back(a[i]);
            solve(sur-siz[a[i]],i);
            if(ans_sz) return;
            b.pop_back();
        }
    }
}

void print(int u,int shape_id,int& cur_node){
    for(int v_shape:nxt[shape_id]){
        int v=++cur_node;
        cout<<v<<" "<<u<<'\n';
        print(v,v_shape,cur_node);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1,0);
    for(int tg=1;tg<=n;tg++){
        solve(tg-1,0);
        
        if(ans_sz){
            int cur_node=1; 
            for(int i=n;i>tg;i--){
                cout<<cur_node<<" "<<cur_node+1<<'\n';
                cur_node++;
            }
            print(cur_node,seed_id,cur_node);
            return 0;
        }

        a.insert(a.end(),c.begin(),c.end());
        c.clear();
        b.clear();
        sort(a.begin(),a.end());
    }
    
    for(int i=1;i<=n;i++){
        for(int j:adj[i]){
            if(i>j) cout<<i<<" "<<j<<'\n';
        }
    }
    //system("pause");
    return 0;
}