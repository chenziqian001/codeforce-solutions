#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
int get(vector<vector<int>> &h,vector<int> &val){
    int n=h.size();
    vector<vector<int>> dp(n,vector<int>(2,inf));
    dp[0][0]=0,dp[0][1]=val[0];
    for(int i=1;i<n;i++){
        for(int x=0;x<2;x++){
            for(int y=0;y<2;y++){
                int ok=1;
                for(int j=0;j<n;j++){
                    ok&=(h[i][j]+x!=h[i-1][j]+y);
                }
                if(ok){
                    if(x==1){
                        dp[i][x]=min(dp[i][x],dp[i-1][y]+val[i]);
                    }
                    else{
                        dp[i][x]=min(dp[i][x],dp[i-1][y]);
                    }
                }
            }
        }
    }
    return min(dp[n-1][0],dp[n-1][1]);
}
void trans(vector<vector<int>> &a){
    int n=a.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(a[i][j],a[j][i]);
        }
    }
}


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> h(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>h[i][j];
        }
    }
    vector<int> A(n);
    vector<int> B(n);
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>B[i];
    int res1=get(h,A);
    trans(h);
    int res2=get(h,B);
    int res=res1+res2;
    if(res>=inf){
        cout<<-1<<'\n';
    }
    else cout<<res<<'\n';

}

signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}