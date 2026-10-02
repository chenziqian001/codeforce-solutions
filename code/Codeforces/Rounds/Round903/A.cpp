#include<bits/stdc++.h>
using namespace std;

bool iss(string s,string t){
    if(s.empty())return true;
    int n=s.size(),m=t.size();
    for(int i=0;i<=m-n;i++){
        int j=0;
        for(;j<n;j++)if(t[i+j]!=s[j])break;
        if(j==n)return true;
    }
    return false;
}

void solve(){
    int n,m;
    cin>>n>>m;
    string x,s;
    cin>>x>>s;
    for(int i=0;i<=6;i++){
        if(iss(s,x)){
            cout<<i<<'\n';
            return;
        }
        x+=x;
    }
    cout<<-1<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}