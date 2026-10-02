#include<bits/stdc++.h>
using namespace std;
#define int long long

int ask(int i,int j){
    cout<<"? "<<i<<" "<<j<<endl;
    int res;cin>>res;
    if(res==-1)exit(0);
    return res;
}
void solve(){
    int n;
    cin>>n;
    int a=-1,b=-1;
    for(int i=1;i+1<=n;i+=2){
        int x=ask(i,i+1);
        int y=ask(i+1,i);
        if(x!=y){
            a=i,b=i+1;
            break;
        }
    }
    if(a==-1){
        cout<<"! "<<n<<endl;
        return;
    }
    int k=(a==1&&b==2)?3:1;
    int x=ask(a,k);
    int y=ask(k,a);
    if(x!=y) cout<<"! "<<a<<endl;
    else cout<<"! "<<b<<endl;

   
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();   
    return 0;
}