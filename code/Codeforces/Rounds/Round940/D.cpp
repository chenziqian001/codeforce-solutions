#include<bits/stdc++.h> 
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<vector<int>> cnt(n+1,vector<int>(31));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            cnt[i][j] = ( (a[i]>>j) & 1 );
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            cnt[i][j] ^= cnt[i-1][j];
        }
    }


    
    vector<vector<array<int,2>>> pre(n+1, vector<array<int,2>>(31, {0,0}));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            pre[i][j][0] = pre[i-1][j][0] + (cnt[i][j]==0);
            pre[i][j][1] = pre[i-1][j][1] + (cnt[i][j]==1);
        }
    }

    vector<vector<array<int,2>>> suf(n+2, vector<array<int,2>>(31, {0,0}));
    for(int i=n;i>=1;i--){
        for(int j=0;j<=30;j++){
            suf[i][j][0] = suf[i+1][j][0] + (cnt[i][j]==0);
            suf[i][j][1] = suf[i+1][j][1] + (cnt[i][j]==1);
        }
    }

    long long res=0;
    for(int i=1;i<=n;i++){
        for(int j=30;j>=0;j--){
            if( (a[i]>>j) & 1 ){
                long long left0 = pre[i-1][j][0]+1;
                long long left1 = pre[i-1][j][1];
                long long right0 = suf[i][j][0];
                long long right1 = suf[i][j][1];
                res += left0 * right0 + left1 * right1;
                break;
            }
        }
    }

    cout<<res<<'\n';
}


signed main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;
}