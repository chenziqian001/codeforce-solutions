#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    map<int,pair<int,int>> mp;
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        if(mp[l].first<r){
            mp[l]={r,i};
        }
    }
    vector<tuple<int,int,int>> gt;
    for(const auto& p:mp){
        int l=p.first,r=p.second.first,id=p.second.second;
        gt.push_back({l,r,id});
    }
    int cnt=1;
    int right=get<1>(gt[0]);
    int f=get<1>(gt[0])-get<0>(gt[0]);
    vector<int> res;
    res.push_back(get<2>(gt[0]));
    for(int i=1;i<gt.size();i++){
        if(get<0>(gt[i])>=right){
            f+=get<1>(gt[i])-get<0>(gt[i]);
            right=get<1>(gt[i]);
            cnt++;
            res.push_back(get<2>(gt[i]));
        }
        else{
            if(get<1>(gt[i])<=right) continue;
            cnt++;
            f+=get<1>(gt[i])-right;
            right=get<1>(gt[i]);
            res.push_back(get<2>(gt[i]));
        }
    }
    cout<<cnt<<'\n';
    for(int num:res){
        cout<<num<<" ";
    }
    cout<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}