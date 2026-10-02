#include<bits/stdc++.h>
using namespace std;
#define int long long

void f1(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> g(n+1);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> d(n+1,-1);
        queue<int> q;
        q.push(1);
        d[1]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:g[u]){
                if(d[v]==-1){
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        string ans="";
        string c="rgb";
        for(int i=1;i<=n;i++) ans+=c[d[i]%3];
        cout<<ans<<'\n';
    }
}

void f2(){
    int t;
    cin>>t;
    while(t--){
        int q;
        cin>>q;
        while(q--){
            int d;
            string s;
            cin>>d>>s;
            char tc=s[0];
            bool hr=s.find('r')!=string::npos;
            bool hg=s.find('g')!=string::npos;
            bool hb=s.find('b')!=string::npos;
            if(hr && hg) tc='g';
            else if(hg && hb) tc='b';
            else if(hb && hr) tc='r';
            for(int i=0;i<d;i++){
                if(s[i]==tc){
                    cout<<i+1<<'\n';
                    break;
                }
            }
        }
    }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string tp;
    cin>>tp;
    if(tp=="first") f1();
    else f2();
    //system("pause");
    return 0;
}