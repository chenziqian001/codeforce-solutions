#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    vector<pair<string,int>> tmp(8);
    for(int i=0;i<8;i++){
        cin>>tmp[i].first>>tmp[i].second;
    }
    int sz=8;
    vector<pair<string,int>> ntmp;
    while(sz>2){
        for(int l=0;l<sz;l+=2){
            if(tmp[l].second>tmp[l+1].second){
                ntmp.push_back(tmp[l]);
            }
            else ntmp.push_back(tmp[l+1]);
        }
        tmp=ntmp;
        ntmp.clear();
        sz/=2;
    }
    if(tmp[0].second>tmp[1].second){
        cout<<tmp[0].first<<" "<<"beats"<<" "<<tmp[1].first<<'\n';
    }
    else{
        cout<<tmp[1].first<<" "<<"beats"<<" "<<tmp[0].first<<'\n';
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
 
 