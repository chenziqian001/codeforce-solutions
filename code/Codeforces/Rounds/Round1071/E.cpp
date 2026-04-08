#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];

    bool okx=false,oky=false;
    for(int i=0;i<n;i++){
        if(s[i]=='0') okx=true;
        if(s[i]=='1') oky=true;
        if(okx && oky) break;
    }
    if(!okx){
        if(x>y-n){
            cout<<"NO"<<'\n';
            return;
        }
    }
    if(!oky){
        if(y>x-n){
            cout<<"NO"<<'\n';
            return;
        }
    }

    int needx=0;
    int needy=0;
    int free=0;

    for(int i=0;i<n;i++){
        int win=p[i]/2+1;
        int lose=p[i]-win;
        if(s[i]=='0'){
            needx+=win;
            free+=lose;
        }
        else{
            needy+=win;
            free+=lose;
        }
    }
    int tt=x+y-needx-needy;
    
    if(needx>x || needy>y || tt<free){
        cout<<"NO"<<'\n';
    }
    else cout<<"YES"<<'\n';
    

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