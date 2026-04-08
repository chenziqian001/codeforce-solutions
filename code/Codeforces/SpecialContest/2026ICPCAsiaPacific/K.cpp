#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int c0=0,c1=0,c25=0;
    for(char c:s){
        if(c=='0'){
            c0++;
        }
        else if(c=='1'){
            c1++;
        }
        else if(c>='2' && c<='5'){
            c25++;
        }
    }

    int l=0,r=n/4,res=0;
    while(l<=r){
        int k=(l+r)/2;
        int L=max({0LL,k-c1,2*k-c0-c1,3*k-c0-c1-c25});
        int R=min(c0,k);

        if(L<=R){
            res=k;
            l=k+1;
        }
        else r=k-1;
    }

    cout<<res<<'\n';

}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}