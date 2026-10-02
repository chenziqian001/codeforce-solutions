#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> d(n),f(n);
    for(int i=0;i<n;i++){
        cin>>d[i];
        cin>>f[i];
    }
    int N=100005;
    vector<int> dp(N+1,-1);
    dp[0]=0;
    int s=0;
    for(int i=0;i<n;i++){
        s=min(N,s+d[i]);
        for(int j=s;j>=d[i];j--){
            if(dp[j-d[i]]!=-1){
                dp[j]=max(dp[j],dp[j-d[i]]+f[i]);
            }
        }
    }
    

    vector<vector<int>> st(N+1,vector<int>(17));
    for(int i=0;i<=N;i++){
        st[i][0]=dp[i];
    }
    for(int j=1;j<17;j++){
        for(int i=0;i+(1<<j)-1<=N;i++){
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
    while(q--){
        int L,R;
        cin>>L>>R;
        int k=__lg(R-L+1);
        cout<<max(st[L][k],st[R-(1<<k)+1][k])<<'\n';
    }





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

