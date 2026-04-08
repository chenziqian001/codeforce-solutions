#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;

void solve(){
    int n,k,v;
    cin>>n>>k>>v;
    v--;
    vector<vector<int>> t(n);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        t[x].push_back(y);
        t[y].push_back(x);
    }

    function<int(int,int)> dfs=[&](int node,int fa)->int{
        int m1=inf,m2=inf;
        for(int next:t[node]){
            if(next==fa) continue;
            int val=dfs(next,node);
            if(val<m1){
                m2=m1;
                m1=val;
            }
            else if(val<m2){
                m2=val;
            }
        }

        if(m1==inf){
            return 1;
        }
        if(m1+m2<=k+1){
            return 1;
        }
        return m1+1;
    };


    if(dfs(v,-1)==1){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
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
