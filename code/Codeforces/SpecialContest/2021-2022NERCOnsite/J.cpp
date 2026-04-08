#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;

    vector<vector<int>> c(n+2,vector<int>(n+2));
    vector<vector<int>> pre(n+2,vector<int>(n+2));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+c[i][j];
        }
    }

    auto sum=[&](int r1,int r2,int c1,int c2)->int{
        if(r1>r2 || c1>c2) return 0;
        return pre[r2][c2]-pre[r1-1][c2]-pre[r2][c1-1]+pre[r1-1][c1-1];
    };


    auto w=[&](int l,int r)->int{
        if(l>r) return 0;
        return sum(l,r,1,n)-sum(l,r,l,r);
    };

    vector<vector<int>> dp(n+2,vector<int>(n+2));
    vector<vector<int>> rt(n+2,vector<int>(n+2));


    for(int len=1;len<=n;len++){
        for(int l=1;l<=n-len+1;l++){
            int r=l+len-1;
            if(len==1){
                dp[l][r]=0;
                rt[l][r]=l;
                continue;
            }
            dp[l][r]=2e18;
            for(int k=l;k<=r;k++){
                int val=dp[l][k-1]+dp[k+1][r]+w(l,k-1)+w(k+1,r);
                if(val<dp[l][r]){
                    dp[l][r]=val;
                    rt[l][r]=k;
                }
            }   
        }
    }

    vector<int> res(n+2);
    function<void(int,int,int)> build=[&](int l,int r,int fa){
        if(l>r) return;
        int k=rt[l][r];
        res[k]=fa;
        build(l,k-1,k);
        build(k+1,r,k);
    };
    build(1,n,0);
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
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