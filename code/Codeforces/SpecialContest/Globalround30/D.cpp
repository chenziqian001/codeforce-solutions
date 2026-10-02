#include<bits/stdc++.h>
using namespace std;
#define int long  long
void solve(){
    int n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;

    vector<int> cnt(n);
    int len=-1e18;
    int i=n-1,j=n-1;
    while(i>=0 && j>=0){
        if(j>i) j=i;
        while(t[i]!= s[j] && j>=0) j--;
        if(i-j>k || j<0){
            cout<<-1<<'\n';
            return;
        }
        cnt[i]=i-j;
        len=max(len,i-j);
        i--;
    }

    cout<<len<<'\n';
    while(len--){
        for(int i=n-1;i>0;i--){
            if(cnt[i]){
                cnt[i]--;
                s[i]=s[i-1];
            }
        }
        cout<<s<<'\n';
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