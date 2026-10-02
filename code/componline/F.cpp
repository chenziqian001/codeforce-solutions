#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve(){
    int n,m;
    cin>>n>>m;
    int p=0;
    int res=0;
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            s+=x;
        }
        if(s<p){
            res++;
        }
        p=s;
    }
    cout<<res<<'\n';


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