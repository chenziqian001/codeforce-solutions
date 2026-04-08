#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int res=0;
    int last=0;


    for(int i=1;i<n;i++){
        int cur=a[i];
        int pre=a[i-1];
        int cop=0;
        if(cur>=pre){
            int cnt=0;
            while(pre*2<=cur){
                cnt++;
                pre*=2;
            }
            cop=max(0LL,last-cnt);
        }
        else{
            int cnt=0;
            while(cur<pre){
                cnt++;
                cur*=2;

            }
            cop=last+cnt;
        }
        res+=cop;
        last=cop;
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