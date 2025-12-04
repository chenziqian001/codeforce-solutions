#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int  n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];


    int q;
    cin>>q;
    vector<vector<array<int,3>>> ask(n);
    for(int i=0;i<q;i++){
        int l,r,x;
        cin>>l>>r>>x;
        ask[r-1].push_back({l-1,x,i});
    }

    vector<vector<int>> dp(13,vector<int>(1<<12,-1));
    dp[0][0]=1e9;
    vector<int> res(q);
    for(int i=0;i<n;i++){
        for(int j=12;j>0;j--){
            for(int st=0;st<(1<<12);st++){
                if(dp[j-1][st]==-1) continue;
                dp[j][st^a[i]]=max(dp[j][st^a[i]],min(dp[j-1][st],i));
            }
        }
        for(auto [l,x,id]:ask[i]){
            for(int j=1;j<=12;j++){
                if(dp[j][x]>=l){
                    res[id]=j;
                    break;
                }
            }
        }
    }
    for(int x:res){
        cout<<x<<" ";
    }
    cout<<'\n';
    //system("pause");
    return 0;

}