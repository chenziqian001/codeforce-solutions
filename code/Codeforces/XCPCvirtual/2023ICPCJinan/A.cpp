#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<pair<int,int>> st;
    st.push_back({-1,0});
    for(int i=0;i<n;i++){
        int t=(s[i]=='(' ||s[i]==')')?0:1;
        if(!st.empty() && st.back().first==t){
            st.pop_back();
            if(st.empty()) continue;
            auto fa=st.back();
            if(fa.second & (1<<t)){
                cout<<"No"<<'\n';
                return;
            }
            st.back().second|=(1<<t);
            
        }
        else{
            st.push_back({t,0});
        }
    }
    cout<<"Yes"<<'\n';
    

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