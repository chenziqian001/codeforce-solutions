#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    s='!'+s;
    vector<vector<int>> f(n+1,vector<int>(26)); 
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++){
            f[i][j]=f[i-1][j]+(s[i]==j+'a');
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int res=0;
        for(int j=0;j<26;j++){
            res=max(res,f[r][j]-f[l-1][j]);
        }
        cout<<res<<'\n';
    }
    

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    //system("pause");
    return 0;
}