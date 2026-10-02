#include<bits/stdc++.h>
using namespace std;
 
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> c0(n);
    vector<int> c1(n);
    int t0=0,t1=0;
    for(int i=0;i<n;i++){
        for(char c:a[i]){
            if(c=='0') c0[i]++;
            else c1[i]++;
        }
        t0+=c0[i];
        t1+=c1[i];
    }
    if(t0==0 || t1==0){
        cout<<0<<'\n';
        return;
    }
    int base=0;
    int tb0=0,tb1=0;
    int sw01=2e18,sw10=2e18;
    for(int i=0;i<n;i++){
        if(c0[i]>c1[i]){
            base+=c1[i];
            tb0++;
            sw01=min(sw01,c0[i]-c1[i]);
        }
        else if(c0[i]<c1[i]){
            base+=c0[i];
            tb1++;
            sw10=min(sw10,c1[i]-c0[i]);
        }
        else{
            tb0++;
            tb1++;
            base+=c0[i];
        }
    }

    if(tb0>0 && tb1>0){
        cout<<base<<'\n';
    }
    else if(tb0==0){
        cout<<base+sw10<<'\n';
    }
    else{
        cout<<base+sw01<<'\n';
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