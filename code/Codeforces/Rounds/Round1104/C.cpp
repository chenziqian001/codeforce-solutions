#include<bits/stdc++.h>
using namespace std;
#define int long long


const int inf=2e18;
void solve(){
    int n;
    cin>>n;
    int mx=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        if(i==0) mx=x;
        else{
            if(mx>x){
                mx+=x;
            }
            else{
                mx=x;
            }
        }
    }
    cout<<mx<<'\n';
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