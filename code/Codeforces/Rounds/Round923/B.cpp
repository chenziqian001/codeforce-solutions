#include<bits/stdc++.h>
using namespace std;
#define int long long




void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> cnt(26);
    string res;
    for(int i=0;i<n;i++){
        int x=a[i];
        for(int j=0;j<26;j++){
            if(cnt[j]==x){
                res+=(j+'a');
                cnt[j]++;
                break;
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