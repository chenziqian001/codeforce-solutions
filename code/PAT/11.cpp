#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    vector<int> a(n);
    for(int i=1;i<n;i++){
        int fa,val;
        cin>>fa>>val;
        a[i]=val;
        t[fa].push_back(i);
    }

    vector<int> res;
    int min_mx=0;


    function<void(int,int)> dfs=[&](int node,int val){
        if(t[node].empty()){
            if(val>min_mx){
                res.clear();
                min_mx=val;
                res.push_back(node);
                return;
            }
            else if(val==min_mx){
                res.push_back(node);
            }
        }
        for(int next:t[node]){
            int nval=min(val,a[next]);
            dfs(next,nval);
        }
    };


    for(int node:t[0]){
        dfs(node,a[node]);
    }
    cout<<min_mx<<'\n';
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i!=res.size()-1){
            cout<<" ";
        }
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