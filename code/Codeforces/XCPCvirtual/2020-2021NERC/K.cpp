#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    cin>>s;
    vector<pair<int,int>> c;
    int x=0,y=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='L')x--;
        else if(s[i]=='R')x++;
        else if(s[i]=='U')y++;
        else y--;
        c.push_back({x,y});
    }
    for(auto o:c){
        int cx=0,cy=0;
        for(int i=0;i<s.size();i++){
            int nx=cx,ny=cy;
            if(s[i]=='L')nx--;
            else if(s[i]=='R')nx++;
            else if(s[i]=='U')ny++;
            else ny--;
            if(nx!=o.first||ny!=o.second){
                cx=nx;
                cy=ny;
            }
        }
        if(cx==0&&cy==0){
            cout<<o.first<<" "<<o.second<<"\n";
            return;
        }
    }
    cout<<"0 0\n";
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