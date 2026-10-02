#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<pair<int,int>> res;

    for(int i=1;i<=n;){
        if(a[i]==i){
            i++;
            continue;
        }
        else{
            int j=n;
            while(j>=1 && a[j]>a[i]) j--;
            res.push_back({i,j});
            sort(a.begin()+i,a.begin()+j+1);
            i++;
        }
    }
    cout<<res.size()<<'\n';
    for(auto [l,r]:res){
        cout<<l<<" "<<r<<'\n';
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
