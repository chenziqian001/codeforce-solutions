#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    
    int res=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        res+=(i-1)*(n-i+1);
    }

    for(int i=2;i<=n;i++){
        int x,y=-1,z;
        z=n+1;
        x=0;
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i]){
                z=j;
                break;
            }
        }

        for(int j=i-1;j>=1;j--){
            if(a[j]<a[i]){
                y=j;
                break;
            }
        }
        if(y==-1) continue;


        for(int j=y-1;j>=0;j--){
            if(a[j]>a[i]){
                x=j;
                break;
            }
        }

        res-=(y-x)*(z-i);
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