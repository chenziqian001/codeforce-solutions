#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int x,y,z,a,b,c;
    cin>>x>>y>>z>>a>>b>>c;
    int res=1e18;

    for(int i=0;i<5000;i++){
        int s = i * b; 
        int tz = z;    
        
        int rx = x - i; 
        int ry = y - i; 
        
        if(rx > 0){
            s += ((rx + 1) / 2) * a; 
            if(rx % 2 == 1) tz--;
        } else if(rx < 0){
            tz += rx; 
        }
        if(ry > 0){
            s += ((ry + 1) / 2) * c; 
            if(ry % 2 == 1) tz--;
        } else if(ry < 0){
            tz += ry;
        }
        if(tz > 0){
            s += ((tz + 1) / 2) * min({a, b, c});
        }
        
        res = min(res, s);
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