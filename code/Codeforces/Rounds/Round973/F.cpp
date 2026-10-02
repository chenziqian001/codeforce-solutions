#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int st,ed;
    cin>>st>>ed;
    st--;
    vector<int> max_d;


    auto dfs=[&](auto&& self,int u,int fa)->int{
        int mx=0;
        bool on_path=false;
        for(int v:g[u]){
            if(v==fa) continue;
            int res=self(self,v,u);
            if(res==-1) on_path=true;
            else mx=max(mx,res+1);
        }
        if(on_path||u==st){
            max_d.push_back(mx);
            return -1;
        }
        return mx;
    };
    dfs(dfs,0,-1);
    reverse(max_d.begin(),max_d.end());

    int m=max_d.size();
    int l=0,r=m-1;
    while(true){
        int a_val=max_d[l]+l;
        bool a_win=true;
        
        for(int j=r;j>l;j--){
            int b_val=max_d[j]+(m-1-j);
            if(b_val>=a_val){
                a_win=false;
                break;
            }
        }
        
        if(a_win){
            cout<<"Alice\n";
            return;
        }
        
        l++;
        if(l==r){
            cout<<"Bob\n";
            return;
        }
        
     
        int b_val=max_d[r]+(m-1-r);
        bool b_win=true;
        
        for(int j=l;j<r;j++){
            int a_val=max_d[j]+j;
            if(a_val>b_val){ 
                b_win=false;
                break;
            }
        }
        
        if(b_win){
            cout<<"Bob\n";
            return;
        }
        
        r--;
        if(l==r){
            cout<<"Alice\n";
            return;
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