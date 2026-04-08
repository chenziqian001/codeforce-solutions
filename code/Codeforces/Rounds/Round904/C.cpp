#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }

    auto f=[&](int pos){
        map<int,int> mp;
        for(auto [l,r]:a){
            if(l>pos || r<pos){
                mp[l]++;
                mp[r+1]--;
            }
        }


        int res=0;
        int s=0;
        for(auto[_,x]:mp){
            s+=x;
            res=max(res,s);
        }
        return res;
    };


    cout<<max(f(1),f(m))<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}