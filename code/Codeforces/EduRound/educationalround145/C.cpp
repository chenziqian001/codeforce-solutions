#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2e9;
void solve(){
    int n,k;
    cin>>n>>k;
    int x=0;
    while((x+1)*(x+2)/2<=k) x++;
    int re=k-x*(x+1)/2;
    vector<int> res(n);
    for(int i=0;i<n;i++){
        if(i<x) res[i]=2;
        else if(i==x) res[i]=-(x-re)*2-1;
        else res[i]=-1000;
    }
    for(int x:res){
        cout<<x<<" ";
    }
    cout<<'\n';
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
 