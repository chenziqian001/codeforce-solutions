#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

void solve(){
    string s;
    cin>>s;
    int pos;
    cin>>pos;
    int cnt=0;
    int n=s.size();
    int cur=n;
    while(pos>cur){
        pos-=cur;
        cur--;
        cnt++;
    }
    string res="";
    for(char c:s){
        while(res.size()&&c<res.back()&&cnt>0){
            res.pop_back();
            cnt--;
        }
        res+=c;
    }
    cout<<res[pos-1];
   
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