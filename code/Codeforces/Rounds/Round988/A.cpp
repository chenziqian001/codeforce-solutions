#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;


void solve(){
    int n;
    cin>>n;
    vector<int> cnt(25);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }


    int res=0;
    for(int x:cnt){
        res+=x/2;
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
}