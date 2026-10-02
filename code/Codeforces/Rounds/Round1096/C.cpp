#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    vector<int> d6;
    vector<int> d2;
    vector<int> d3;
    vector<int> dick;
    vector<int> res;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%6==0){
            d6.push_back(x);
        }
        else if(x%3==0){
            d3.push_back(x);
        }
        else if(x%2==0) d2.push_back(x);
        else dick.push_back(x);
    }
    for(int x:d6) cout<<x<<" ";
    for(int x:d3) cout<<x<<" ";
    for(int x:dick) cout<<x<<" ";
    for(int x:d2) cout<<x<<" ";
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