#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> x(k+1),y(k+1);
    for(int i=1;i<=n;i++){
        x[2*i-1]=i;
        y[2*i-1]=i;
        x[2*i]=i;
        y[2*i]=(i%n)+1;
    }
    int cur=2*n+1;
    for(int i=1;i<=n&&cur<=k;i++){
        for(int j=1;j<=n&&cur<=k;j++){
            if(j==i || j==(i%n)+1) continue;
            x[cur]=i;
            y[cur]=j;
            cur++;
        }
    }
    for(int i=1;i<=k;i++){
        cout<<x[i]<<" "<<y[i]<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) solve();
    //system("pause");
    return 0;
}