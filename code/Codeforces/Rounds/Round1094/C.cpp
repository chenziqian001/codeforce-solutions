#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b.begin()+1,b.end());
    
    int m=b[(n+1)/2];
    vector<int> dp(n+1,-1);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        int x=0,y=0,z=0;
        for(int j=i-1;j>=0;j--){
            if(a[j+1]>m) x++;
            else if(a[j+1]<m) y++;
            else z++;
            if((i-j)%2 && dp[j]!=-1 && z>abs(x-y)){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    cout<<dp[n]<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}