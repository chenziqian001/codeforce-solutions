#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int  cur=0;
    
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            cur++;
            if(cur>=(m-1)){
                cout<<"NO"<<'\n';
                return;
            }
        }
        else{
            cur=0;
        }
    }
    cout<<"YES"<<'\n';

    



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