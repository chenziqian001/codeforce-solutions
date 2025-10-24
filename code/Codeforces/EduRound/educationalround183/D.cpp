#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    int mk=n*(n-1)/2;
    vector<vector<int>> dp(n+1,vector<int>(mk+1,0));
    vector<vector<int>> p(n+1,vector<int>(mk+1,-1));
    dp[0][0]=true;
    for(int j=0;j<n;j++){
        for(int x=0;x<=mk;x++){
            if(!dp[j][x]) continue;
            for(int y=1;y<=n-j;y++){
                int add=y*(y-1)/2;
                if(x+add<=mk && !dp[j+y][x+add]){
                    dp[j+y][x+add]=1;
                    p[j+y][x+add]=y;
                }
            }
        }

    }
    k=mk-k;
    if(!dp[n][k]){
        cout<<0<<'\n';
        return;
    }
    vector<int> bloc;
    int cur=n,curk=k;
    while(cur){
        int y=p[cur][curk];
        bloc.push_back(y);
        curk-=y*(y-1)/2;
        cur-=y;
    }

    reverse(bloc.begin(),bloc.end());

    vector<int> res;
    int now=n+1;
    for(int y:bloc){
        for(int st=now-y;st<now;st++){
            res.push_back(st);
        }
        now-=y;
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
  






