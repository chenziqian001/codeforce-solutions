#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;

void solve(){
    cin>>n>>k;
    int mid=n+1;
    int cur=1;
    int count=0;
    while(n>=k){
        if(n&1) count+=cur;
        n>>=1;
        cur<<=1;
    }
    cout<<count*mid/2<<'\n';
}


signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}