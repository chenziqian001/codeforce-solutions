#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    vector<string> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=b[i][j]) cnt++;
        }
    }
    if(cnt<=n*m/2){
        for(int i=0;i<n;i++){
            cout<<a[i]<<'\n';
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='.'){
                    cout<<'X';
                }
                else cout<<'.';
            }
            cout<<'\n';
        }
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


