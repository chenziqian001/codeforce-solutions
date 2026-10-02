#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        mp[a[i]].push_back(i);
    }
    int res=0;
    for(int i=0;i<n;i++){
        int l=a[i];
        for(int j=i;j<n;j++){
            int m=a[j];
            int r=2*m-l;
            if(mp.find(r)==mp.end()) continue;
            else{
                int k=mp[r].back();
                int odd=min(j-i,k-j)*2+1;
                int eve=min(j-i+1,k-j)*2;
                res=max({res,odd,eve});
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


