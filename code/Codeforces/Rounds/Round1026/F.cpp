#include<bits/stdc++.h>
using namespace std;
#define int long long 


void solve(){
    int n;
    cin>>n;
    int mx=0;
    int res=0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        int x=a[i];
        if(x<=mx){
            res=max(res,x%mx+mx%x); // x+ymodx<=y
            //m2<=f(m1,m2)<=res<=m1
        }
        else if(x<mx*2){
            mx=x;
            res=x;
            //   mx<=nmx<=2*mx, res=nmx
        }
        else{
            //最大值至少翻倍了，这个循环撑死不超过30次
            mx=x;
            for(int j=0;j<=i;j++){
                res=max(res,mx%a[j]+a[j]%mx);
            }
        }
        cout<<res<<" ";
    }
    cout<<'\n';

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