#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    vector<string> res;
    string s;
    cin>>s;
    int n=s.size();
    string cur="";
    for(int i=n-1;i>=0;i--){
        cur+=s[i];
        if(cur.size()==3){
            reverse(cur.begin(),cur.end());
            res.push_back(cur);
            cur="";
        }
    }
    reverse(cur.begin(),cur.end());
    if(cur!="") res.push_back(cur);
    int m=res.size();
    for(int i=m-1;i>0;i--){
        cout<<res[i]<<',';
    }
    cout<<res[0];
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

