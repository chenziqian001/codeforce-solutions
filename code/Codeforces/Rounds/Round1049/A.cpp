#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt0=0;
    for(char c:s){
        if(c=='0') cnt0++;
    }
    int res=0;
    for(int i=0;i<cnt0;i++){
        if(s[i]=='1') res++;

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