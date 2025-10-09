#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k;
    cin>>n>>k;
    priority_queue<int> pq;
    int res=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        pq.push(x);
        if((n-i+1)%(k+1)==0){
            int val=pq.top();
            pq.pop();
            res+=val;
        }
    }
    cout<<res<<'\n';

}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}