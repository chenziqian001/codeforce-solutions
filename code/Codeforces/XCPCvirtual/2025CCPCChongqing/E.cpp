#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++) cin>>a[i].second;
    for(int i=0;i<n;i++) cin>>a[i].first;
    sort(a.rbegin(),a.rend());
    


    int l=0,r=n;
    int res=l;
    while(l<=r){
        int mid=(l+r)/2;
        priority_queue<int> pq;
        int s=0;
        bool ok=false;
        for(int i=0;i<n;i++){
            pq.push(a[i].second);
            s+=a[i].second;
            if(pq.size()>mid){
                int x=pq.top();
                s-=x;
                pq.pop();
            }
            if(pq.size()==mid && a[i].first*mid>=s){
                ok=true;
                break;
            }
        } 
        if(ok){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
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