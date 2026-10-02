#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    vector<vector<int>> t(n);
    for(int i=1;i<n;i++){
        int fa;
        cin>>fa;
        fa--;
        t[fa].push_back(i);
    }
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];

    vector<int> opt(n);
    vector<set<int>> s(n);
    vector<int> vis;
    vector<int> cnt(n+1);


    function<void(int)> dfs=[&](int node){
        if(!t[node].size()){
            opt[node]=0;
            s[node].insert(c[node]);
            return;
        }
        int h=-1,mf=1,mx=0;
        int sum=0;
        for(int next:t[node]){
            dfs(next);
            sum+=opt[next];
            if(s[next].size()>mx){
                mx=s[next].size();
                h=next;
            }
        }
        
        
        for(int next:t[node]){
            if(next==h) continue;
            for(int x:s[next]){
                if(!cnt[x]) vis.push_back(x);
                cnt[x]++;
            }
        }

        for(int x:vis){
            int f=cnt[x]+(s[h].count(x)?1:0);
            mf=max(mf,f);
        }
        opt[node]=sum+t[node].size()-mf;
        if(mf==1){
            swap(s[node],s[h]);
            for(int x:vis) s[node].insert(x);
        }
        else{
            for(int x:vis){
                if(cnt[x]+(s[h].count(x)?1:0)==mf){
                    s[node].insert(x);
                }
            }
        }
        for(int x:vis){
            cnt[x]=0;
        }
        vis.clear();
    };
    dfs(0);
    cout<<opt[0]+1<<'\n';


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

