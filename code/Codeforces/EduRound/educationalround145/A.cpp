#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    map<int,int> mp;
    for(char c:s){
        mp[c-'0']++;
    }
    vector<int> v;
    for(auto [x,y]:mp){
        v.push_back(y);
    } 
    sort(v.rbegin(),v.rend());
    if(v.size()==1){
        cout<<-1<<'\n';
        return;
    }
    int tt=accumulate(v.begin(),v.end(),0LL);
    int mx=*max_element(v.begin(),v.end());
    if(mx*2<=tt){
        cout<<n<<'\n';
    }
    else{
        int re=mx*2-tt;
        cout<<mx+re*2-1<<'\n';
    }
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
 