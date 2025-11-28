#include<bits/stdc++.h>
using namespace std;
#define int long long



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int res=0;

    priority_queue<pair<int,pair<int,int>>> pq;
    auto val=[&](int len,int nums){
        int base=len/nums;
        int extra=len-base*nums;
        return (nums-extra)*base*base+extra*(base+1)*(base+1);
    };

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        res+=x*x;
        pq.push({val(x,1)-val(x,2),{x,2}});
    }


    for(int i=0;i<k-n;i++){
        res-=pq.top().first;
        int len=pq.top().second.first;
        int pt=pq.top().second.second;
        pq.pop();

        pq.push({val(len,pt)-val(len,pt+1),{len,pt+1}});
    }


    cout<<res<<'\n';
    //system("pause");

}






