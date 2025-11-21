#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    priority_queue<int> pq;
    int res=0;
    for(int i=1;i<=n;i++){
        pq.push(-a[i]);
        if(!pq.empty() && pq.top()+a[i]>0){
            res+=pq.top()+a[i];
            pq.pop();
            pq.push(-a[i]);
        }
        
    }

    cout<<res<<'\n';



    //system("pause");
}