#include<bits/stdc++.h>
using namespace std;
#define int long long
 
struct node{
    int val,st;
    vector<int> use;
    bool operator<(const node& o) const{
        if(val!=o.val) return val>o.val;
        else return st>o.st;
    };
};


void solve(){
    int n;
    cin>>n;
    map<int,int> odd,even;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%2==1) odd[x]++;
        else even[x]++;
    }

    vector<node> a;
    function<void(int,int,vector<int>&)> dfs=[&](int val,int st,vector<int> &use){
        a.push_back({val,st,use});
        int need1=val-1;
        if(even.find(need1)!=even.end()){
            int nval=val+need1;
            use.push_back(need1);
            dfs(nval,st,use);
            use.pop_back();
        }
        int need2=val+1;
        if(even.find(need2)!=even.end()){
            int nval=val+need2;
            use.push_back(need2);
            dfs(nval,st,use);
            use.pop_back();
        }
    };

    for(auto [x,_]:odd){
        vector<int> use;
        dfs(x,x,use);
    } 
    sort(a.begin(),a.end());

    vector<int> res;


    for(auto& p:a){
        if(odd[p.st]==0)continue;
        map<int,int> need;
        for(int e:p.use)need[e]++;
        int mn=odd[p.st];
        for(auto& [e,c]:need){
            mn=min(mn,even[e]/c);
        }
        if(mn>0){
            odd[p.st]-=mn;
            for(auto& [e,c]:need)even[e]-=mn*c;
            for(int i=0;i<mn;i++)res.push_back(p.val);
        }
    }

    for(auto [x,cnt]:even){
        while(cnt--){
            res.push_back(x);
        }
    }
    cout<<res.size()<<'\n';
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
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
 
 