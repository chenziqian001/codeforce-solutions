#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int res=0;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x){
            pq.push(x);
        }
        else{
            if(!pq.empty()){
                int v=pq.top();
                pq.pop();
                res+=v;
            }

        }
    }
    cout<<res<<'\n';
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
