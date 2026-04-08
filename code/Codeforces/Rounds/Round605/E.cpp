#include<bits/stdc++.h>
using namespace std;
#define int long long


vector<int> bfs(int n,vector<vector<int>> &g,vector<int> points){
    queue<int> q;
    vector<int> dis(n,-1);
    for(int x:points){
        dis[x]=0;
        q.push(x);
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        
        for(int next:g[node]){
            if(dis[next]!=-1) continue;
            dis[next]=dis[node]+1;
            q.push(next);
        }
    }
    return dis;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<vector<int>> reg(n);
    vector<int> odds;
    vector<int> evens;


    for(int i=0;i<n;i++){
        int x=a[i];
        int left=i-a[i];
        int right=i+a[i];
        if(a[i]%2==0){
            evens.push_back(i);
        }
        else{
            odds.push_back(i);
        }

        if(right<n){
            reg[right].push_back(i);
        }
        if(left>=0){
            reg[left].push_back(i);
        }
    }

    vector<int> oddans=bfs(n,reg,evens);
    vector<int> evenans=bfs(n,reg,odds);
    vector<int> res(n);
    for(int i=0;i<n;i++){
        int x=a[i];
        if(x%2==0){
            res[i]=evenans[i];
        }
        else{
            res[i]=oddans[i];
        }
    }

    for(int x:res){
        cout<<x<<" ";
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