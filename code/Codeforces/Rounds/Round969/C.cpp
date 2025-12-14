#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    int g=__gcd(a,b);
    
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
        c[i]%=g;
    }

    sort(c.begin(),c.end());
    int res=c[n-1]-c[0];
    for(int i=1;i<n;i++){
        res=min(res,c[i-1]-(c[i]-g));
    }

    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}