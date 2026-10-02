#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,m;
    cin>>n>>m;
    int tt=0;
    vector<map<string,int>> ch(1);
    vector<int> del(1),sa(1);

    auto ins=[&](string s,int tp){
        int u=0,sz=s.size();
        string cur="";
        for(int i=0;i<=sz;i++){
            if(i==sz || s[i]=='/'){
                if(!ch[u].count(cur)){
                    ch[u][cur]=++tt;
                    ch.push_back(map<string,int>());
                    del.push_back(0);
                    sa.push_back(0);
                }
                u=ch[u][cur];
                if(tp) del[u]=1;
                else sa[u]=1;
                cur="";
            }
            else cur+=s[i];
        }
    };

    function<int(int)> dfs=[&](int node)->int{
        if(node!=0 && del[node] && !sa[node]) return 1;
        int res=0;
        for(auto &p:ch[node]){
            res+=dfs(p.second);
        }
        return res;
    };
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        ins(s,1);
    }
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        ins(s,0);
    }
    cout<<dfs(0)<<'\n';
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