#include<iostream>
#include<vector>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> p(n);
    vector<int> d(n);
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>d[i];
    p.insert(p.begin(),0);
    d.insert(d.begin(),0);
    int m=n+1;
    vector<int> dp(m);
    vector<bool> vis(m,false);
    dp[0]=0;

    auto find_len=[&](int pos){
        int cnt=0;
        while(!vis[pos]){
            vis[pos]=true;
            pos=p[pos];
            cnt++;
        }
        return cnt;
    };

    for(int i=1;i<m;i++){
        if(vis[d[i]]) dp[i]=dp[i-1];
        else{
            dp[i]=dp[i-1]+find_len(d[i]);
        }
    }
    for(int i=1;i<m;i++){
        cout<<dp[i]<<" ";
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}