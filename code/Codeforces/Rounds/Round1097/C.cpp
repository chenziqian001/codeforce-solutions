#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            x+=a[i]=='('?1:-1;
            y+=a[i]=='('?1:-1;
        }
        else{
            if(x<y) x++,y--;
            else x--,y++;
        }
        if(x<0 || y<0){
            cout<<"NO"<<'\n';
            return;
        }
    }
    if(x || y){
        cout<<"NO"<<'\n';
        return;
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