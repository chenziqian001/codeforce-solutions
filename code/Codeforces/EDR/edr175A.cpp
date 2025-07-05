#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int ans=3*(n/15);
    n%=15;
    for(int i=0;i<=n;i++){
        int mod3=i%3;
        int mod5=i%5;
        if(mod3==mod5) ans++;
    }
    cout<<ans<<'\n';
    return;
}
int main(){
   int t;
   cin>>t;
   while(t--) solve();
   system("pause");
   return 0;
}