#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,k;
    cin>>n>>k;

    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]={x,i+1};
    }
    vector<int> res;
    int sum=0;
    vector<pair<int,int>> na;
    while(true){
        int sz=a.size();
        for(int i=0;i<sz;i++){
            auto [val,id]=a[i];
            if(val<=k){
                res.push_back(id);
            }
            else{
                sum+=val;
                na.push_back({val,id});
            }
        }
        if(na.empty()) break;
        a=na;
        na.clear();
        k=sum/a.size();
        sum=0;
        reverse(a.begin(),a.end());
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i!=res.size()-1){
            cout<<" ";
        }
    }
    cout<<'\n';


    
    
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