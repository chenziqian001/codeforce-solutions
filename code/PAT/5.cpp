#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int a;
        string b;
        cin>>a>>b;
        mp[a]=0;
        for(char c:b){
            if(c=='1'){
                mp[a]=1;
            }
        } 
    }
    vector<int> res;
    
    for(auto [x,y]:mp){
        if(y==0){
            res.push_back(x);
        }
    }
    if(res.size()==0){
        cout<<"NONE"<<'\n';
    }
    else{
        for(int x:res){
            cout<<x<<" ";
        }
        cout<<'\n';
    }
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