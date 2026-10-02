#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,k;
    cin>>n>>k;

    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    int l=0,r=k*2;

    auto check=[&](int m)->bool{
        vector<pair<int,int>> s;
        for(int i=0;i<n;i++){
            if(a[i].first<=m){
                int d=m-a[i].first;
                s.push_back({max(0LL,a[i].second-d),a[i].second+d});
            }
        }
        sort(s.begin(),s.end());

        int len=0;
        for(int i=0;i<s.size();i++){
            if(s[i].first<=len){
                len=max(len,s[i].second+1);
            }
            else break;
        }
        return len>k;
    };
    int res=r;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<res<<'\n';
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

