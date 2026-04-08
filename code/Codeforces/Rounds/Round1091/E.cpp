#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;

    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    vector<int> d(n);
    for(int i=0;i<n;i++) cin>>d[i];
    
    vector<int> cnt(n);
    
    
    for(int i=n-1;i>=0;i--){
        int cur=p[i];
        int c=0;
        for(int j=i+1;j<n;j++){
            if(p[j]>cur) c++;
        }
        cnt[i]=c;
        if(d[i]>c){
            cout<<-1<<'\n';
            return;
        }
    }


    vector<int> res(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<n;i++){
        if(cnt[i]==d[i]){
            pq.emplace(p[i],i);
        }
    }
    int val=1;
    vector<bool> vis(n,false);
    while(!pq.empty()){
        auto [x,id]=pq.top();
        pq.pop();
        res[id]=val++;
        vis[id]=true;
        for(int i=0;i<id;i++){
            if(!vis[i] && p[i] < x){
                cnt[i]--;
                if(cnt[i]==d[i]){
                    pq.emplace(p[i],i);
                }
                else if(cnt[i]<d[i]){
                    cout<<-1<<'\n';
                    return;
                }
            }
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
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}
