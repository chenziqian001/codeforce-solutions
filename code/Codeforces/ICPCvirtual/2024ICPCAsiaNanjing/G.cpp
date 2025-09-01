#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    auto query = [&](int x, int y) {
        
        cout << "? " << ++x << " " << ++y << '\n';
        fflush(stdout);
        cin >> x;
        return x;
    };
    auto answer = [&](int x){
        cout<<"! "<<++x<<'\n';
        fflush(stdout);
    };
    vector<vector<int>> t(n);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        if(l!=-1) t[i].push_back(l),t[l].push_back(i);
        if(r!=-1) t[i].push_back(r),t[r].push_back(i);
    }
    int s=0;
    while(true){
        vector<int> siz(n),mx(n);
        auto dfs = [&](auto&& dfs, int u, int fa) -> void {
            siz[u] = 1;
            for (int v : t[u]) {
                if (v == fa) continue;
                dfs(dfs, v, u); 
                siz[u] += siz[v];
                mx[u] = max(mx[u], siz[v]);
            }
        };
        dfs(dfs,s,-1);
        int ctr;
        int tot=siz[s];
        for(int u=0;u<n;u++){
            mx[u]=max(mx[u],tot-siz[u]);
            if(siz[u] && mx[u]<=tot/2) ctr=u;
        }
        if(t[ctr].empty()){
            answer(ctr);
            break;
        }
        else if(t[ctr].size()==1){
            int u=ctr,v=t[ctr][0];
            int x=query(u,v);
            if(x==0){
                answer(u);
                break;
            }
            else {
                answer(v);
                break;
            }
        }
        else{
            sort(t[ctr].begin(),t[ctr].end(),[&](const int u,const int v){
                return mx[u]<mx[v];
            });
            int u=t[ctr][0],v=t[ctr][1];
            int x=query(u,v);
            if(x==0){
                s=u;
                t[s].erase(find(t[s].begin(),t[s].end(),ctr));
            }
            else if(x==2){
                s=v;
                t[s].erase(find(t[s].begin(),t[s].end(),ctr));
            }
            else{
                s=ctr;
                t[s].erase(find(t[s].begin(),t[s].end(),u));
                t[s].erase(find(t[s].begin(),t[s].end(),v));
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}
