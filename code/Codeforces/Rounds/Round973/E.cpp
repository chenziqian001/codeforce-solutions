#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int g=0;
    int res=0;
    int cnt=n;
    while(1){
        int m=a[0];
        for(int i=0;i<n;i++){
            int x=__gcd(g,a[i]);
            if(x<m){
                m=x;
            }
        }
        if(m==g) break;
        g=m;
        cnt--;
        res+=m;
    
    }

    res+=g*cnt;
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