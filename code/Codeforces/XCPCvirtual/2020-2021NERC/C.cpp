#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int q;
    cin>>q;
    priority_queue<pair<int,int>> pq;
    set<int> vis;
    int id=1;
    int cus=1;
    while(q--){
        int x;
        cin>>x;
        
      
        if(x==1){
            int y;
            cin>>y;
            pq.push({y,-id});
            id++;
        }
        else if(x==2){
            while(vis.count(cus)) cus++;
            vis.insert(cus);
            cout<<cus<<" "; 
        }
        else{
            while(!pq.empty() && (vis.count(-pq.top().second))) pq.pop();
            vis.insert(-pq.top().second);
            cout<<-pq.top().second<<" ";
            pq.pop();
        }
    }

   

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