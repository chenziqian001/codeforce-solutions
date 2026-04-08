#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    
    while(q--){
        int l,r;
        cin>>l>>r;
        int m=r-l+1;
        int st=l-1;

        vector<int> pi(m),b(m),dp(m);
        int res=0;

        for(int i=1;i<m;i++){
            int j=pi[i-1];
            while(j>0 && s[st+i]!=s[st+j]) j=pi[j-1];
            if(s[st+i]==s[st+j]) j++;
            pi[i]=j;
            if(j==0) b[i]=0;
            else if(pi[j-1]==0) b[i]=j;
            else b[i]=b[j-1];
        }
        for(int i=0;i<m;i++){
            dp[i]=dp[i-b[i]]+1;
            res+=dp[i];
        }
        cout<<res<<'\n';

    }

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
