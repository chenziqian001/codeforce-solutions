#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int a,b;
    cin>>a>>b;
 
 
    queue<array<int,3>> q;
    q.push({a,b,0});
    while(!q.empty()){
        auto [x,y,s]=q.front();
        q.pop();
 
        if(x==0 || y==0){
            cout<<s+1<<'\n';
            return;
        }
 
        q.push({x-__gcd(x,y),y,s+1});
        q.push({x,y-__gcd(x,y),s+1});
    }
 
 
 
 
 
    
 
 
 
    
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

