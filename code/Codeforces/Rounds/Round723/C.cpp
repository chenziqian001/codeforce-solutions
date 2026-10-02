#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> pq;
    int sum=0;
    int len=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum+=x;
        len++;
        pq.push(x);
        if(sum<0){
            sum-=pq.top();
            len--;
            pq.pop();
        }
    }
    cout<<len<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--)solve();
    //system("pause");
    return 0;
}