#include<bits/stdc++.h>
using namespace std;
#define int long long





void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> p(n+1);
    
    vector<vector<int>> t(n+1);
    for(int i=2;i<=n;i++){
        cin>>p[i];
        t[p[i]].push_back(i);
    }

    vector<int> d(n+1);

    auto get=[&](auto& self, int u)->void{
        for(int v:t[u]){
            d[v]=d[u]+1;
            self(self,v);
        }
    };
    get(get,1);
    vector<int> a;
    int mx=-1;
    int id=-1;
    for(int i=1;i<=n;i++){
        if(d[i]>=mx){
            mx=d[i];
            id=i;
        }
    }

    while(id!=0){
        a.push_back(id);
        id=p[id];
    }
    reverse(a.begin(),a.end());



    if(k<=a.size()){
        cout<<k-1<<'\n';
        for(int i=0;i<k;i++){
            cout<<a[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    vector<int> c(n+1),ina(n+1);
    for(int x:a){
        ina[x]=c[x]=1;
    }
    int m=a.size();
    queue<int> q;
    for(int x:a){
        q.push(x);
    }

    while(m<k){
        int u=q.front();
        q.pop();
        for(int v:t[u]){
            if(!c[v]){
                c[v]=true;
                m++;
                q.push(v);
                if(m==k) break;
            }
        }

    }

    vector<int> res;

    function<void(int)> dfs=[&](int node){
        res.push_back(node);
        int rd=-1;
        for(int next:t[node]){
            if(c[next]){
                if(ina[next]) rd=next;
                else {
                    dfs(next);
                    res.push_back(node);
                }
            }
        }
        if(rd!=-1){
            dfs(rd);
        }
    };
    dfs(1);
    cout<<res.size()-1<<'\n';
    for(int x:res){
        cout<<x<<" ";
    }
    cout<<'\n';






    


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}