#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    int qn=sqrt(n)+2;
    int qm=sqrt(m)+2;
    vector<vector<bool>> bad(qn+1,vector<bool>(qm+1));
    for(int i=2;i<=min(qn,qm);i++){
        for(int a=i;a<=qn;a+=i){
            for(int b=i;b<=qm;b+=i){
                bad[a][b]=true;
            }
        }
    }
    int res=0;
    for(int i=1;i*i<=n;i++){
        for(int j=1;j*j<=m;j++){
            if(bad[i][j]) continue;
            res+=min(n/(i+j)/i,m/(i+j)/j);
        }
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