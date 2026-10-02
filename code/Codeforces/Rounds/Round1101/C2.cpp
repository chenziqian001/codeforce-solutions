#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n,x,s;
    cin>>n>>x>>s;
    string S;
    cin>>S;
    int desk=0,tt=0;
    int cnt=0;
    for(char c:S){
        if(c=='I'){
            if(desk<x) desk++;
            else if(cnt) {
                cnt--;
                tt++;
            }
        }
        else if(c=='E'){
            if(tt<desk*(s-1)) tt++;
        }
        else{
            if(desk<x){
                desk++;
                cnt++;
            }
            else if(tt<desk*(s-1)) tt++;
        }
        cnt=min(cnt,(desk*(s-1)-tt)/s);
    }
    cout<<desk+tt<<'\n';
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