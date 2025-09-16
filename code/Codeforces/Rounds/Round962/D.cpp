#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;
    cin>>n>>x;
    int res=0;
    for(int a=1;a<=min(n,x);a++){
        for(int b=1;a+b<=x && a*b<=n;b++){
            int hc=min((n-a*b)/(a+b),x-a-b);
            res+=hc;
        }
    }
    cout<<res<<'\n';



}



int main(){
    int t;
    cin>>t;
    while(t--) solve();
    system("pause");
    return 0;
}