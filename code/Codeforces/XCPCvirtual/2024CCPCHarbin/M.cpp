#include <bits/stdc++.h>
using namespace std;
#define int long long
int get(int x,int d){
    while(d>=2){
        if(x%d==0){
            return x/d;
        }
        else d--;
    }
    return x;
}


void solve(){
    int n;
    cin>>n;
    vector<int> d;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            d.push_back(i);
            if(i*i!=n) d.push_back(n/i);
        }
    }
    sort(d.begin(),d.end());
    int res=0;
    int m=d.size();
    for(int i=0;i<m;i++){
        int l=d[i];
        int r=(i==m-1)?n:d[i+1]-1;
        res+=(r-l+1)*(n/d[i]);
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
    return 0;
}


