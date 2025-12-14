#include <bits/stdc++.h>
using namespace std;
#define int long long





void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> pos(k+1);
    
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        x=min(x,k);
        for(int j=1;j<=x;j++){
            pos[j].push_back(i);
        }
    }

    vector<vector<vector<pair<int,int>>>> dp(k+1,vector<vector<pair<int,int>>>(k+1));
    dp[0][0].emplace_back(0,0);
    int res=0;
    for(int c=0;c<=k;c++){
        for(int mx=0;mx<=c;mx++){
            if(dp[c][mx].empty()) continue;
            sort(dp[c][mx].begin(), dp[c][mx].end(),[](const pair<int,int>& a, const pair<int,int>& b) {
                if (a.first!=b.first) return a.first<b.first;
                return a.second>b.second;
            });

            vector<pair<int,int>> candi;
    
            int maxi=-1;
            for(auto pa:dp[c][mx]){
                if(pa.second>maxi){
                    candi.emplace_back(pa);
                    maxi=pa.second;
                }
            }
            res=max(res,maxi);



            for(auto pa:candi){
                for(int nmx=mx+1;nmx+c<=k;nmx++){
                    auto it=upper_bound(pos[nmx].begin(),pos[nmx].end(),pa.first);
                    if(it!=pos[nmx].end()){
                        int nid=*it;
                        int inc=(nmx-mx)*(n-nid+1);
                        dp[c+nmx][nmx].emplace_back(nid,inc+pa.second);
                    }
                }
            }
        }
    }


    cout<<res<<'\n';
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}
