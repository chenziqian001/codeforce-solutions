#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    vector<int> a(6);
    for(int i=0;i<6;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> values={1};
    for(int x:a){
        values.push_back(x+1);
    }
    int k;
    cin>>k;
    vector<int> wins;
    for(int x:values){
        wins.push_back(lower_bound(a.begin(),a.end(),x)-a.begin());
    }
    
    const int INF(1LL<<62);
    int dp[7][20];
    int previous[7][20]={};
    int chosen[7][20]={};
    for(auto &row:dp){
        fill(begin(row),end(row),INF);
    }
    
    dp[0][0]=0;
    for(int i=0;i<6;++i){
        for(int w=0;w<=19;++w){
            if(dp[i][w]==INF)continue;
            for(int j=0;j<(int)values.size();++j){
                int nw=min(19LL,w+wins[j]);
                int cost=dp[i][w]+values[j];
                if(cost<dp[i+1][nw]){
                    dp[i+1][nw]=cost;
                    previous[i+1][nw]=w;
                    chosen[i+1][nw]=values[j];
                }
            }
        }
    }
    if(dp[6][19]>k){
        cout<<"NO"<<'\n';
        return;
    }
    vector<int> b(6);
    int w=19;
    for(int i=6;i>=1;--i){
        b[i-1]=chosen[i][w];
        w=previous[i][w];
    }
    b[0]+=k-dp[6][19];
    cout<<"YES\n";
    for(int i=0;i<6;++i){
        cout<<b[i]<<(i==5?'\n':' ');
    }   
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
}