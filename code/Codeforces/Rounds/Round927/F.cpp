#include<bits/stdc++.h>
using namespace std;


/*
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(m,vector<int>(2));
    vector<vector<int>> del(n+1);
    vector<int> cnt(n+1);
    for(int i=0;i<m;i++){
        cin>>a[i][0]>>a[i][1];
        cnt[a[i][0]]++;
        del[a[i][1]].push_back(a[i][0]);
    }

    vector<int> dp(n+1);
    multiset<int> st;
    
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        for(int j=0;j<cnt[i];j++) st.insert(i);
        if(!st.empty()) dp[i]=max(dp[i],dp[*st.begin()-1]+(int)st.size());
        for(int d:del[i]){
            st.erase(st.find(d));
        }
    }

    cout<<dp[n]<<'\n';

}
*/
//事实上我们可以回忆一下使用multiset的初衷，由于我们的dp定义式子的含义是dp[i]为前i
//步可以达到的最大喂猫数，所以我们的任务就是找出当前点喂猫能影响到的最远区间

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> dp(n);
    vector<int> far(n,n);
    vector<int> sum(n);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        far[r]=min(far[r],l);
        sum[l]++;
        if(r+1<n) sum[r+1]--;
    }
    
    for(int i=1;i<n;i++){
        sum[i]+=sum[i-1];
    }
    for(int i=n-2;i>=0;i--){
        far[i]=min(far[i],far[i+1]);
    }
    for(int i=0;i<n;i++){
        dp[i]+=sum[i];
        if(far[i]>0){
            dp[i]+=dp[far[i]-1];
        }
        if(i>0){
            dp[i]=max(dp[i-1],dp[i]);
        }
    }
    cout<<dp[n-1]<<'\n';




}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}
