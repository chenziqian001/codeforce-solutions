#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    for(int i=0;i<m;i++) cin>>a[i];
    vector<int> rk(n+1,inf);
    rk[1]=m-1;
    for(int i=1;i<=n;i++){
        for(int j=i+i;j<=n;j+=i){
            rk[j]=min(rk[j],rk[i]-1);
        }
    }
    for(int i=1;i<=n;i++){
        if(rk[i]<0) {
            cout<<-1<<'\n';
            return;
        }
    }


    for(int i=1;i<=n;i++){
        cout<<a[rk[i]]<<" ";
    }
    cout<<'\n';

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