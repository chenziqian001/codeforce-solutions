#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int cnt=3;
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);
    pq.push(1);
    pq.push(3);
    while(pq.top()<n){
        int a,b;
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        a=b*2+1;
        pq.push(a);
        pq.push(b);
        cnt++;
    }
    cout<<cnt<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}