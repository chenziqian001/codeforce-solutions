#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> a(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    sort(a.begin(),a.end());
    int res=k;
    int right=k;
    for(int i=0;i<n;i++){
        if(a[i][1]<=res) continue;
        if(a[i][0]>res) break;
        right=max(right,a[i][1]);
        res=max(res,a[i][2]);
    }
    cout<<res<<'\n';


}


int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}