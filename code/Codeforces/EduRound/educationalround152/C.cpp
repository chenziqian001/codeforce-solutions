#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    
    vector<int> nxt(n+2,n+1),prv(n+2);
    
    for(int i=1;i<=n;i++) prv[i]=(s[i-1]=='0'?i:prv[i-1]);
    for(int i=n;i>=1;i--) nxt[i]=(s[i-1]=='1'?i:nxt[i+1]);
    
    vector<pair<int,int>> v;
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        int L=nxt[l],R=prv[r];
        if(L>R) v.push_back({-1,-1});
        else v.push_back({L,R});
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    cout<<v.size()<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}