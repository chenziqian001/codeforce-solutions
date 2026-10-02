#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    int m=a[0];
    int cnt=0;
    for(int i=0;i<3;i++){
        if(a[i]%m!=0){
            cout<<"NO"<<'\n';
            return;
        }
        cnt+=(a[i]/m)-1;
    }
    if(cnt<=3)cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
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