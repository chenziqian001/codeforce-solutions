#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;

    for(int i=0;i<n;i++){
        
        cnt++;
        if(s[i]=='L') break;
    }
    cout<<cnt<<'\n';
    


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    //system("pause");
    return 0;
}