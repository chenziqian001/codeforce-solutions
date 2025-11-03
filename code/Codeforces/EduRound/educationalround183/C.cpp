#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=' '+s;
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+(s[i]=='a'?-1:1);
    }
    int d=pre[n];
    if(d==0){
        cout<<0<<'\n';
        return;
    }
    map<int,int> mp;
    int res=n;
    for(int i=0;i<=n;i++){
        if(mp.find(pre[i]-d)!=mp.end()){
            res=min(res,i-mp[pre[i]-d]);
        }
        mp[pre[i]]=i;
    }


    if(res==n){
        cout<<-1<<'\n';
    }
    else cout<<res<<'\n';
    

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}