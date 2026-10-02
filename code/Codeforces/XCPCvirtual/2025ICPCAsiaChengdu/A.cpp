#include<bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin>>s;
    int n=s.size();
    s=' '+s;
    bool valid=true;
    int rst=n;
    if(n<5){
        cout<<"No"<<'\n';
        return;
    }
    while(rst>=1 && s[rst]=='>') rst--;
    rst++;
    if(rst-1<1) valid=false;
    if(s[1]=='-') valid=false;
    if(n-rst+1<3) valid=false;
    if(!valid){
        cout<<"No"<<'\n';
        return;
    }
    vector<pair<int,int>> ans;
    for(int i=n;i>=rst+2;i--){
        ans.push_back({1,i});
    }
    for(int i=2;i<rst;i++){
        if(s[i]=='>') ans.push_back({i,rst-i+3});
    }
    int m=ans.size();
    cout<<"Yes"<<" "<<ans.size()<<'\n';
    
    for(int i=0;i<m;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    }

}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}