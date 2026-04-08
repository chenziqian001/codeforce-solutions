#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;



    for(int i=1;i<n-1;i++){
        if(s[i-1]=='1' && s[i+1]=='1'){
            s[i]='1';
        }
    }
    int c1=0;
    for(char c:s){
        c1+=c=='1';
    }

    int maxi=c1;

    for(int i=1;i<n-1;i++){
        if(s[i-1]=='1' && s[i+1]=='1'){
            s[i]='0';
            c1--;
        }
    }
    cout<<c1<<" "<<maxi<<'\n';



    




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
