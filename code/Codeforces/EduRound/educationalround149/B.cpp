#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int res=2;
    int cur=1;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            cur++;
            res=max(res,cur+1);
        }
        else cur=1;
    }
    cout<<res<<'\n';
    




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