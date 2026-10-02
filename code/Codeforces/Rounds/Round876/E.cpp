#include <bits/stdc++.h>
using namespace std;
#define int long long





signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1),c(n+1);
    int s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }

    vector<vector<bool>> dp(n+1,vector<bool>((s/2)+10));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=s/2;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i]) dp[i][j]=dp[i][j]|dp[i-1][j-a[i]];
        }
    }

    if(s%2==0 && dp[n][s/2]){
        cout<<"Second"<<endl;
        int v=s/2;
        for(int i=n;i>=1;i--){
            if(v>=a[i] && dp[i-1][v-a[i]]){
                c[i]=1;
                v-=a[i];
            }
            else c[i]=0;
        }
        while(1){
            int x;
            cin>>x;
            if(x<=0) break;
            int y=0;
            for(int i=1;i<=n;i++){
                if(a[i]>0 && c[i]!=c[x]){
                    if(!y|| a[i]>a[y]) y=i;
                }
            }
            cout<<y<<endl;
            int d=min(a[x],a[y]);
            a[x]-=d;
            a[y]-=d;
        }
    }
    else{
        cout<<"First"<<endl;
        while(1){
            int x=0;
            for(int i=1;i<=n;i++){
                if(a[i]>0){
                    if(!x || a[i]>a[x]) x=i;
                }
            }
            if(!x) break;
            cout<<x<<endl;
            int y;
            cin>>y;
            if(y<=0) break;
            int d=min(a[x],a[y]);
            a[x]-=d;
            a[y]-=d;
        }
    }
}