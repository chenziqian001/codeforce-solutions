#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int pa[N];
int find(int x){
    if(x!=pa[x]){
        pa[x]=find(pa[x]);
    }
    return pa[x];
}
bool merge(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx==fy) return false;
    pa[fx]=fy;
    return true;
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) pa[i]=i;
    vector<vector<int>> g(n+1);
    vector<int> u(m);
    vector<int> v(m);
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i];
        g[u[i]].push_back(i);
        g[v[i]].push_back(i);
    }
    string res(m,'0');
    for(int i=0;i<m;i++){
        int x=u[i],y=v[i];
        if(merge(x,y)){
            res[i]='1';
        }
    }
    set<int> st;
    set<int> edge;
    for(int i=0;i<m;i++){
        if(res[i]=='0'){
            st.insert(u[i]);
            st.insert(v[i]);
            edge.insert(i);
        }
    }
    if(st.size()==3){
        int node=*st.begin();
        bool ok=true;
        for(int e:g[node]){
            if(ok && edge.count(e)){
                res[e]='1';
                ok=false;
            }
            else res[e]='0';

        }
        cout<<res<<'\n';
    }
    else{
        cout<<res<<'\n';
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